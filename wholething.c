#include"header.h"
void menu(int elem);
void game(int resume,char *user);
char* change_user(char *actual);
int wrong_password(char *user);

void menu(int elem)
{	int poz=1,userswitch=0,quit=0;
	char c,user[20],copy[20];
	strcpy(user,get_user());					//iau ultimul user logat
	clear();
	menu_ART(user);										
	mvprintw(12,50,"Quit");
	mvprintw(11,46,"Hall of Fame");
	if(elem==4)											//afisare meniu(3 elemente sau 4)
	{	attron(A_UNDERLINE);
		mvprintw(9,49,"Resume");
		attroff(A_UNDERLINE);
		mvprintw(10,48,"New Game");
	}
	else
	{	attron(A_UNDERLINE);
		mvprintw(10,48,"New Game");
		attroff(A_UNDERLINE);
	}
	c=getch();
	strcpy(copy,user);							
	while(tolower(c)!='\n')						//navigare meniu
	{	if(c==65)
			poz=pos_det(poz,-1,elem);
		if(c==66)
			poz=pos_det(poz,1,elem);
		if(elem==3)
			afisare_meniu3(poz);
		else
			afisare_meniu4(poz);
		if(tolower(c)=='u')						//user change
		{	strcpy(user,change_user(user));
			menu_ART(user);
		}
	strcpy(user,get_user());
	menu_ART(user);
	if(strcmp(copy,user)!=0)
	{	userswitch=1;
		break;
	}
	c=getch();
	}
	if(userswitch==1)
		menu(3);								//noul user nu are drept la resume
	else
	{	if(elem-poz==1)					//hall of fame
		{	highscore();
			menu(elem);
		}
		if(elem==poz)
		{	
			endwin();
			quit=1;
		}
		if(elem-poz==2)
			game(0,user);					//start newgame
		if((poz==1) && (elem==4))
			game(1,user);					//resume
	}

}
void game(int resume,char *user)
{	int v[16],u[16],i,valoare,pozitie,valid1,valid2,valid3,valid4,tastavalid=0,validvalid=0;
	int ab=2,score=0,gameover,decoy,a,b,c,d,win=0,afterwin=0,quit=0;
	int motivation=0;
	char ch;
	FILE *file;
	clear();
	for(i=0; i<16; i++)
			v[i]=0;
	srand(time(NULL));
	pozitie=rand()%16;
	valoare=rand()%2;
	if(valoare==0)
		v[pozitie]=2;
	else
		v[pozitie]=4;
	while(v[pozitie]!=0)
		pozitie=rand()%16;
	valoare=rand()%2;
	if(valoare==0)
		v[pozitie]=2;
	else
		v[pozitie]=4;
	if(resume==1)				//daca nu e new_game, accesez valorile
	{	progress_save(1,v);
		track_of_score(&score,1);
	}
	for(i=0;i<16;i++)		//daca am deja 2048, inseamna ca am castigat deja si am ales sa continui
		if(v[i]>=2048)
			afterwin=1;
	afisare(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15],score,0);
	ch=getch();
	while(1)					//astept taste
	{	tastavalid=0;
		validvalid=0;
		valid1=1;
		valid2=1;
		valid3=1;
		valid4=1;
		gameover=0;
		motivation=0;
		for(i=0;i<16;i++)		//cate casute am ocupate
			if(v[i]!=0)
				gameover++;
		
			
		if(ch==66)				//jos
		{	if((mutare(&v[12],&v[8],&v[4],&v[0],&score)==0) & (mutare(&v[13],&v[9],&v[5],&v[1],&score)==0) & (mutare(&v[14],&v[10],&v[6],&v[2],&score)==0) & (mutare(&v[15],&v[11],&v[7],&v[3],&score)==0))
				valid1=0;
			tastavalid=1;
		}
		if(ch==65)	//sus
		{	if((mutare(&v[0],&v[4],&v[8],&v[12],&score)==0) & (mutare(&v[1],&v[5],&v[9],&v[13],&score)==0) & (mutare(&v[2],&v[6],&v[10],&v[14],&score)==0) & (mutare(&v[3],&v[7],&v[11],&v[15],&score)==0))
				valid2=0;
			
			tastavalid=1;
		}
		if(ch==68)		//stanga
		{	if((mutare(&v[0],&v[1],&v[2],&v[3],&score)==0) & (mutare(&v[4],&v[5],&v[6],&v[7],&score)==0) & (mutare(&v[8],&v[9],&v[10],&v[11],&score)==0) & (mutare(&v[12],&v[13],&v[14],&v[15],&score)==0))
				valid3=0;
			tastavalid=1;
		}
		if(ch==67)	 	//dreapta
		{	if((mutare(&v[3],&v[2],&v[1],&v[0],&score)==0) & (mutare(&v[7],&v[6],&v[5],&v[4],&score)==0) & (mutare(&v[11],&v[10],&v[9],&v[8],&score)==0) & (mutare(&v[15],&v[14],&v[13],&v[12],&score)==0))
				valid4=0;
			tastavalid=1;
		}
		clear();
		if((valid1==1) && (valid2==1) && (valid3==1) && (valid4==1) && (tastavalid==1))
		{	srand(time(NULL));		//daca tasta apasata si miscarile coloanelor au fost valide
			pozitie=rand()%16;		//generez random
			valoare=rand()%2;
			while(v[pozitie]!=0)
				pozitie=rand()%16;
			if(valoare==0)
				v[pozitie]=2;
			else
				v[pozitie]=4;
			
		}
		else
			
			if((gameover==16) && (auto_move(v,1,1,1,1)==0))	//daca sunt toate casutele sunt ocupate
				gameover=17;									//si nu exista o miscare ipotetica care ar elibera
		
		if(tolower(ch)=='m')			//motivation
			motivation=1;
		if((tolower(ch)=='e') || (ch==ERR))	//auto-move(la buton sau la timeout)
		{	a=1;
			b=1;
			c=1;
			d=1;
			for(i=0;i<16;i++)			//copii cu care lucrez
				u[i]=v[i];
			if((mutare(&u[12],&u[8],&u[4],&u[0],&decoy)==0) && (mutare(&u[13],&u[9],&u[5],&u[1],&decoy)==0) && (mutare(&u[14],&u[10],&u[6],&u[2],&decoy)==0) && (mutare(&u[15],&u[11],&u[7],&u[3],&decoy)==0))
				a=0;
			if((mutare(&u[0],&u[4],&u[8],&u[12],&decoy)==0) && (mutare(&u[1],&u[5],&u[9],&u[13],&decoy)==0) && (mutare(&u[2],&u[6],&u[10],&u[14],&decoy)==0) && (mutare(&u[3],&u[7],&u[11],&u[15],&decoy)==0))
				b=0;
			if((mutare(&u[0],&u[1],&u[2],&u[3],&decoy)==0) && (mutare(&u[4],&u[5],&u[6],&u[7],&decoy)==0) && (mutare(&u[8],&u[9],&u[10],&u[11],&decoy)==0) && (mutare(&u[12],&u[13],&u[14],&u[15],&decoy)==0))
				c=0;
			if((mutare(&u[3],&u[2],&u[1],&u[0],&decoy)==0) && (mutare(&u[7],&u[5],&u[6],&u[4],&decoy)==0) && (mutare(&u[11],&u[10],&u[9],&u[8],&decoy)==0) && (mutare(&u[15],&u[14],&u[13],&u[12],&decoy)==0))
				d=0;
			switch(auto_move(v,a,b,c,d)) //mutarea care imi elibereaza cele mai multe casute
			{	case 1 :
					mutare(&v[12],&v[8],&v[4],&v[0],&score);
					mutare(&v[13],&v[9],&v[5],&v[1],&score);
					mutare(&v[14],&v[10],&v[6],&v[2],&score);
					mutare(&v[15],&v[11],&v[7],&v[3],&score);
					break;
				case 2 :
					mutare(&v[0],&v[4],&v[8],&v[12],&score);
					mutare(&v[1],&v[5],&v[9],&v[13],&score);
					mutare(&v[2],&v[6],&v[10],&v[14],&score);
					mutare(&v[3],&v[7],&v[11],&v[15],&score);
			
					break;
				case 3 :
					mutare(&v[0],&v[1],&v[2],&v[3],&score);
					mutare(&v[4],&v[5],&v[6],&v[7],&score);
					mutare(&v[8],&v[9],&v[10],&v[11],&score);
					mutare(&v[12],&v[13],&v[14],&v[15],&score);
			
					break;
				case 4 :
					mutare(&v[3],&v[2],&v[1],&v[0],&score);
					mutare(&v[7],&v[6],&v[5],&v[4],&score);
					mutare(&v[11],&v[10],&v[9],&v[8],&score);
					mutare(&v[15],&v[14],&v[13],&v[12],&score);
				
					break;
			}
				gameover=0;
				for(i=0;i<16;i++)
					if(v[i]!=0)
						gameover++;				//cate castue pline am dupa mutare
				if(gameover<16)
				{	srand(time(NULL));
					pozitie=rand()%16;
					valoare=rand()%2;
					while(v[pozitie]!=0)
						pozitie=rand()%16;
					if(valoare==0)
						v[pozitie]=2;
					else
						v[pozitie]=4;
				}
				else
					gameover=17;		//gameover
		}
		
		afisare(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15],score,0);
		if(gameover==17)
		{	sregister(user,score);
			gameoverf(user);
			break;
		}
		if(tolower(ch)=='q')		//quit
		{	ab=2;									//contor-par-Yes,impar-No
			mvprintw(7,34,"Are you sure you want to quit?");
			mvprintw(8,35,"(Your progress will be saved)");
			mvprintw(10,49,"No");
			attron(A_UNDERLINE);
			mvprintw(9,49,"Yes");
			attroff(A_UNDERLINE);
			ch=getch();
			while(tolower(ch)!='\n')
			{	if((ch==65) || (ch==66))
					ab++;
				if(ab%2==1)
				{	mvprintw(9,49,"Yes");
					attron(A_UNDERLINE);
					mvprintw(10,49,"No");
					attroff(A_UNDERLINE);
				}
				else
				{	mvprintw(10,49,"No");
					attron(A_UNDERLINE);
					mvprintw(9,49,"Yes");
					attroff(A_UNDERLINE);
				}
				ch=getch();
			}
			if(ab%2==0)
			{	quit=1;
				break;
			}
			mvprintw(7,34,"                              ");
			mvprintw(8,34,"                              ");
			mvprintw(9,45,"          ");
			mvprintw(10,45,"         ");
			curs_set(0);
		}
		
				progress_save(0,v);
		track_of_score(&score,0);
		
		for(i=0; i<16; i++)
			if((v[i]==2048) && (afterwin==0))
				win=1;						//win
				
		if(win==1)
		{	sregister(user,score);
			afterwin=1;					//am terminat jocul
			if(winf(user)==0)
				break;
			win=0;							//in cazul in care continui, nu mai vreau sa intre in acest if
		
		}
		afisare(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15],score,1);
		if(motivation==1)
			get_motivated();
		ch=getch();					//noul caracter
	}
	if(((afterwin==0) || (gameover==17)) && (quit==0))
		menu(3);							//daca am pierdut , nu am resume
	else
		menu(4);							//altfel(am iesit), am resume
}

int main()
{	char c;
	initscr();
	halfdelay(70);					//timeout pt auto-move
	noecho();
	start_color();
	menu(3);
	endwin();
return 0;
}

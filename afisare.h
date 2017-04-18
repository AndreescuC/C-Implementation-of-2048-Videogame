void individual(int nr,int rand, int col)				//functie care imi diferentiaza valorile
{	init_color(COLOR_RED,255,255,180);						//afisand fiecare valoare(+casutele inconjuratoare)
	init_pair(1,COLOR_BLACK,COLOR_WHITE);					//in culoarea corespunzatoare
	init_pair(2,COLOR_WHITE,COLOR_YELLOW);				//in pozitia corespunzatoare
	init_pair(3,COLOR_WHITE,COLOR_CYAN);					//functia nu afiseaza decat puterile lui 2	
	init_pair(4,COLOR_WHITE,COLOR_BLUE);					//prin urmare nu va afisa 0(casuta goala)
	init_pair(5,COLOR_WHITE,COLOR_GREEN);
	init_pair(6,COLOR_WHITE,COLOR_MAGENTA);
	init_pair(7,COLOR_WHITE,COLOR_RED);
	init_pair(8,COLOR_WHITE,COLOR_BLACK);
	switch(nr)
	{	case 2 :
			attron(COLOR_PAIR(1));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+1," ");
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(1));
			break; 
		case 4 :
			attron(COLOR_PAIR(1));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+1," ");
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(1));
			break;
		case 8 :
			attron(COLOR_PAIR(1));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+1," ");
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(1));
			break;
		case 16 :
			attron(COLOR_PAIR(2));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(2));
			break;
		case 32 :
			attron(COLOR_PAIR(3));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(3));
			break;
		case 64 :
			attron(COLOR_PAIR(4));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+2," ");
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(4));
			break;
		case 128 :
			attron(COLOR_PAIR(5));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(5));
			break;
		case 256 :
			attron(COLOR_PAIR(6));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(6));
			break;
		case 512 :
			attron(COLOR_PAIR(7));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand,col+3," ");
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(7));
			break;
		case 1024 :
			attron(COLOR_PAIR(8));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(8));
			break;
		case 2048 :
			attron(COLOR_PAIR(8));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(8));
			break;
		case 4096 :
			attron(COLOR_PAIR(1));	
			mvprintw(rand,col,"%d",nr);
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(1));
			break;
		case 8192 :
			attron(COLOR_PAIR(2));											//programul meu este facut pentru afisarea a valorii
			mvprintw(rand,col,"%d",nr);									//maxime 8192
			mvprintw(rand+1,col,"_");
			mvprintw(rand+1,col+1,"_");
			mvprintw(rand+1,col+2,"_");
			mvprintw(rand+1,col+3,"_");
			attroff(COLOR_PAIR(2));
			break;
	}
}
void afisare(int a,int b,int c,int d,int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2,int a3,int b3,int c3,int d3,int score, int clear)
{	if(clear==1)															//functie de afisare
		clear();																//primeste cele 16 valori(casute)+scor(pt afisare)+clear
	curs_set(0);															//clear are rolul de a determina daca functia apeleaza
	time_t t;																	//sau nu clear()
	time(&t);			
	mvprintw(1,1,"%s",ctime(&t));							//Legenda-inceput
	attron(COLOR_PAIR(3));
	mvprintw(14,1,"   ");
	mvprintw(15,1," Q ");
	mvprintw(16,1,"   ");
	attroff(COLOR_PAIR(3));
	mvprintw(15,5,"Return to main menu");
	attron(COLOR_PAIR(4));
	mvprintw(17,1,"   ");
	mvprintw(18,1," M ");
	mvprintw(19,1,"   ");
	attroff(COLOR_PAIR(4));
	mvprintw(18,5,"Get motivated !");
	attron(COLOR_PAIR(5));
	mvprintw(20,1,"   ");
	mvprintw(21,1," E ");
	mvprintw(22,1,"   ");
	attroff(COLOR_PAIR(5));
	mvprintw(21,5,"Got stuck ? Auto-move");
	attron(COLOR_PAIR(6));
	mvprintw(25,46,"       ");
	mvprintw(26,46,"  Up   ");
	mvprintw(27,46," arrow ");
	mvprintw(28,46,"       ");
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(7));
	mvprintw(29,46,"       ");
	mvprintw(30,46," Down  ");
	mvprintw(31,46," arrow ");
	mvprintw(32,46,"       ");
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(3));
	mvprintw(29,39,"       ");
	mvprintw(30,39," Left  ");
	mvprintw(31,39," arrow ");
	mvprintw(32,39,"       ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
	mvprintw(29,53,"       ");
	mvprintw(30,53," Right ");
	mvprintw(31,53," arrow ");
	mvprintw(32,53,"       ");
	attroff(COLOR_PAIR(4));											//Legenda-sfarsit
	mvprintw(1,78,"Score: %d ", score);					//Scor
	mvprintw(16,44,"|");												//Tabelul-inceput
	mvprintw(17,44,"|");
	mvprintw(18,44,"|");
	mvprintw(19,44,"|");
	mvprintw(20,44,"|");
	mvprintw(21,44,"|");
	mvprintw(22,49,"|");
	mvprintw(16,49,"|");
	mvprintw(17,49,"|");
	mvprintw(18,49,"|");
	mvprintw(19,49,"|");
	mvprintw(20,49,"|");
	mvprintw(21,49,"|");
	mvprintw(22,44,"|");
	mvprintw(16,54,"|");
	mvprintw(17,54,"|");
	mvprintw(18,54,"|");
	mvprintw(19,54,"|");
	mvprintw(20,54,"|");
	mvprintw(21,54,"|");
	mvprintw(22,54,"|");
	mvprintw(16,54,"|");
	mvprintw(16,39,"|");
	mvprintw(18,39,"|");
	mvprintw(20,39,"|");
	mvprintw(22,39,"|");
	mvprintw(23,39,"|");
	mvprintw(16,59,"|");
	mvprintw(18,59,"|");
	mvprintw(20,59,"|");
	mvprintw(22,59,"|");
	mvprintw(23,59,"|");
	mvprintw(15,40,"___________________");
	mvprintw(23,39,"|____|____|____|____|");
	mvprintw(17,39,"|____|____|____|____|");
	mvprintw(19,39,"|____|____|____|____|");
	mvprintw(21,39,"|____|____|____|____|");						//Tabelul-sfarsit
	individual(a,16,40);																//apelez pt fiecare variabila functia individual
	individual(b,16,45);
	individual(c,16,50);
	individual(d,16,55);
	individual(a1,18,40);
	individual(b1,18,45);
	individual(c1,18,50);
	individual(d1,18,55);
	individual(a2,20,40);
	individual(b2,20,45);
	individual(c2,20,50);
	individual(d2,20,55);
	individual(a3,22,40);
	individual(b3,22,45);
	individual(c3,22,50);
	individual(d3,22,55);
}


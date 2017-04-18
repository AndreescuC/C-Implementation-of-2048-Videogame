afisare_meniu3(int poz)									//fisierul contine 2 functii de afisare
{	if(poz==1)														//Prima(afisare_meniu3) este folosita in cazul unui meniu3
	{	mvprintw(12,50,"Quit");							//adica un meniu cu doar 3 optiuni(New Game,Hall of fame,Quit)
		mvprintw(11,46,"Hall of Fame");			//primeste ca parametru pozitia pe care te afli in meniu
		attron(A_UNDERLINE);								//si afiseaza elementele meniului editate corespunzator
		mvprintw(10,48,"New Game");
		attroff(A_UNDERLINE);
	}
	if(poz==2)
	{	mvprintw(10,48,"New Game");
		mvprintw(12,50,"Quit");
		attron(A_UNDERLINE);
		mvprintw(11,46,"Hall of Fame");
		attroff(A_UNDERLINE);
	}
	if(poz==3)
	{	mvprintw(10,48,"New Game");
		mvprintw(11,46,"Hall of Fame");
		attron(A_UNDERLINE);
		mvprintw(12,50,"Quit");
		attroff(A_UNDERLINE);
	}
}
afisare_meniu4(int poz)									//Analog, folosita insa pt un meniu format si din Resume
{	
	if(poz==1)
	{	mvprintw(10,48,"New Game");
		mvprintw(12,50,"Quit");
		mvprintw(11,46,"Hall of Fame");
		attron(A_UNDERLINE);
		mvprintw(9,49,"Resume");
		attroff(A_UNDERLINE);
	}
	if(poz==2)
	{	mvprintw(9,49,"Resume");
		mvprintw(12,50,"Quit");
		mvprintw(11,46,"Hall of Fame");
		attron(A_UNDERLINE);
		mvprintw(10,48,"New Game");
		attroff(A_UNDERLINE);
	}
	if(poz==3)
	{	mvprintw(10,48,"New Game");
		mvprintw(9,49,"Resume");
		mvprintw(12,50,"Quit");
		attron(A_UNDERLINE);
		mvprintw(11,46,"Hall of Fame");
		
		attroff(A_UNDERLINE);
	}
	if(poz==4)
	{	mvprintw(10,48,"New Game");
		mvprintw(9,49,"Resume");
		mvprintw(11,46,"Hall of Fame");
		attron(A_UNDERLINE);
		
		mvprintw(12,50,"Quit");
		attroff(A_UNDERLINE);
	}
}
int pos_det(int a, int b, int elem)						//Fisierul contine si o functie pt determinare pozitiei
{	if(b==1)																		//O functie generica ce functioneaza pe oricate elemente
		if(a!=elem)																//a-pozitia actuala
			a=a+1;																	//b-actiune(1 pt sageata jos,-1pt sageata sus)		
		else																			//elem-numarul de elemente ale meniului
			a=1;
	if(b==-1)
		if(a!=1)
			a=a-1;
		else
			a=elem;
return a;																			//returneaza noua pozitie
}

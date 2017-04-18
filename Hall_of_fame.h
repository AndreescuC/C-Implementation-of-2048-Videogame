typedef struct scor{			//functie ce afiseaza highscores
	char user[20];					//foloseste structura scor
	int score;
}scor;
void highscore()
{	FILE *file;
	int n,i;
	char c;
	scor v[50];
	file=fopen("highscores.txt","r");
	fscanf(file,"%d", &n);
	for(i=0;i<n;i++)								//atribui fiecarui element al vectorului o pereche user-score
	{	fscanf(file,"%s",v[i].user);
		fscanf(file,"%d", &v[i].score);
	}
	fclose(file);
	clear();
	attron(A_BOLD);
	mvprintw(2,30,"Player");
	mvprintw(2,50,"Score");
	attroff(A_BOLD);
	for(i=0;i<n;i++)
	{	mvprintw(4+i,30,"%d.%s", i+1,v[i].user);
		mvprintw(4+i,50,"%d",v[i].score);
	}
	c=getch();
	while(c==ERR)									//ma asigur ca halfdelay-ul nu imi iese din functie
		c=getch();
}

char* new_user()										//creez un nou user si intorc username-ul
{	FILE *file,*newfile;
	char c,*s,pass1[20],pass2[20],nume[20],parola[20];
	int i,a=0,check_nume=0,n,nu_conteaza;
	s=malloc(20*sizeof(char));
	mvprintw(4,75,"  Please insert your name:");
	mvprintw(5,75,"(no more than 20 characters)");
	c=getch();
	attron(A_BOLD);
	mvprintw(9,75,"  Press backspace ");
	mvprintw(10,75,"to retype your name");
	attroff(A_BOLD);
	while(c!='\n')		
	{	while(c==ERR)										//ma asigur ca halfdelay-ul nu introduce in username
			c=getch();
		s[a]=c;													//primesc cate un caracter pe rand si il introduc in noul nume
		mvprintw(7,79+a,"%c", c);
		a++;
		c=getch();
		if(c==127)											//daca se apasa backspace, eliberez stelutele si ii dau lui a 0
		{	mvprintw(7,79,"                            ");
			a=0;
			c=getch();
		}
	}
	s[a]='\0';							//terminator de sir
	
	while(1)							//analog introducere parola
	{	mvprintw(4,72,"   Please insert your password:");
		mvprintw(5,75,"(no more than 20 characters)");
		mvprintw(9,75,"                         ");
		mvprintw(10,72,"                                  ");
		mvprintw(7,79,"                              ");
		c=getch();
		a=0;
		attron(A_BOLD);
		mvprintw(9,75,"    Press backspace ");
		mvprintw(10,75,"to type a new password");
		attroff(A_BOLD);
		while(1)
		{	while(c==ERR)
				c=getch();
			pass1[a]=c;
			mvprintw(7,79+a,"*");
			a++;
			c=getch();
			if(c==127)
			{	mvprintw(7,79,"                            ");
				a=0;
				c=getch();
			}
			if(c=='\n')
				break;
		}
		pass1[a]='\0';
		mvprintw(7,79,"                  ");
																										//cer inca o data parola
		a=0;
		mvprintw(4,75,"Please retype your password:  ");
		mvprintw(5,75,"                               ");
		mvprintw(9,75,"                         ");
		mvprintw(10,75,"                              ");
		mvprintw(7,79,"                              ");
		c=getch();
		attron(A_BOLD);
		mvprintw(9,75,"    Press backspace ");
		mvprintw(10,75,"to type a new password");
		attroff(A_BOLD);
		while(1)
		{	while(c==ERR)
				c=getch();
			pass2[a]=c;
			mvprintw(7,79+a,"*");
			a++;
			c=getch();
			if(c==127)
			{	mvprintw(7,79,"                            ");
				a=0;
				c=getch();
			}
			if(c=='\n')
				break;
		}
		pass2[a]='\0';
		
		if(strcmp(pass1,pass2)==0)			//verific parolele
			break;												//daca verifica, ies din while(1)
		else
		{	mvprintw(9,75,"Passwords do not match   ");
			mvprintw(10,72,"Press any key to try again !      ");
			c=getch();
			while(c==ERR)
				c=getch();
		}
	}
	mvprintw(4,75,"                                     ");	//fac modificarile de riguare in fisiere
	mvprintw(7,79,"                                     ");
	file=fopen("users.txt","r");
	newfile=fopen("copyusers.txt", "w");			
	fscanf(file,"%d", &n);
	fprintf(newfile,"%d\n", n+1);						//pe prima linie, noul numar de useri
	for(i=0;i<n;i++)
	{	fscanf(file,"%s %s",nume,parola);
		fprintf(newfile,"%s %s\n",nume,parola);
	}
		fprintf(newfile,"%s %s\n", s,pass1);
	fclose(file);
	fclose(newfile);
	file=fopen("users.txt","w");
	newfile=fopen("copyusers.txt","r");
	fprintf(file,"%d\n",n+1);
	fscanf(newfile,"%d",&nu_conteaza);
	for(i=0; i<n+1; i++)
	{	fscanf(newfile,"%s %s",nume,parola);
		fprintf(file,"%s %s\n",nume,parola);
	}
	fclose(file);
	fclose(newfile);
	mvprintw(9,7,"                                ");
	mvprintw(10,75,"                              ");
	file=fopen("curent_user.txt","w");
	fprintf(file,"%s\n",s);
	fclose(file);
return s;

}
	

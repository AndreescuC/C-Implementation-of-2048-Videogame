int wrong_password(char *user)					//intoarce 1(mai incerc o data),0(ma intorc la meniu)
{	char c;
	int ret=1;
	mvprintw(4,52,"Yaycks !! You're not really %s, aren't you? /:)", user);
	mvprintw(5,65,"T -- try again               ");
	mvprintw(6,65,"R -- return to main menu");
	c=getch();
	while((tolower(c)!='t') && (tolower(c)!='r'))
		c=getch();
	if(tolower(c)=='t')
	{	mvprintw(4,52,"                                                 ");
		mvprintw(5,55,"                                              ");
		mvprintw(6,55,"                                              ");
		ret=1;
	}
	else
		ret=0;
return ret;


		
}

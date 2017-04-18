void get_motivated()				//functie ce apleaza(random) unul dintre cele 10 mesaje "motivationale"
{	int select;
	char c='"';
	srand(time(NULL));
	select=rand()%10;
	switch(select)
	{	case 0 :
			mvprintw(7,27,"%c Sometimes when I close my eyes, I can't see...%c",c,c);
			
			break;
		case 1 :
			mvprintw(7,27,"If a cute saying is all it takes to motivate you,");
			mvprintw(8,27,"        you probably have a very easy job.");
			mvprintw(9,27,"      The kind robots will be doing soon.");
			break;
		case 2 :
			mvprintw(7,27,"        You're doing great....I guess");
			break;
		case 3 :
			mvprintw(7,23,"You do realise you could be playing the original game, right?");
			break;
		case 4 :
			mvprintw(7,27,"               Here a thought :");
			mvprintw(8,27,"  It could be that the purpose of your life");
			mvprintw(9,28,"   is only to serve as a warning to others");
			break;
		case 5 :
			mvprintw(7,27,"Not everyone gets to be an astronaut when they grow up...");
			break;
		case 6 :
			mvprintw(7,27,"        If you're not part of the solution...");
			mvprintw(8,26,"There's good money to be made in prolonging the problem $_$");
			break;
		case 7 :
			mvprintw(7,27,"             Pro tip : Press keys");
			break;
		case 8 :
			mvprintw(7,27,"  Just wait.The auto-move will do the job for you");	
			break;
		case 9 :
			mvprintw(7,27,"       If you listen closely, you can hear");
			mvprintw(8,27," little vietnamese kids moving the squares around,");
			mvprintw(9,27,"           doing all the job for you");
			mvprintw(10,27,"         (I'm kidding....or am I not ?)");
			break;
		
	}
	
}

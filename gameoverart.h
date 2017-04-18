void gameoverf(char *s)					//functie de afisare mesaj de Game Over
{	char c;												//primeste username
	init_pair(3,COLOR_WHITE,COLOR_CYAN);
	attron(COLOR_PAIR(3));	
	mvprintw(14,41,"Great run, %s !", s);
	attroff(COLOR_PAIR(3));	
	mvprintw(1,29," ****        ***      ***   ***  ******");
	mvprintw(2,29,"*           *   *     *  * *  *  *      ");
	mvprintw(3,29,"*          *     *    *   *   *  *      ");
	mvprintw(4,29,"*   ***   *********   *       *  *****  ");
	mvprintw(5,29,"*     *  *         *  *       *  *      ");
	mvprintw(6,29," *****  *           * *       *  ******");
	mvprintw(8,31," ****** *          * *******  *****  ");
	mvprintw(9,31,"*      * *        *  *        *    * ");
	mvprintw(10,31,"*      *  *      *   *        * ***  ");
	mvprintw(11,31,"*      *   *    *    ******   **     ");
	mvprintw(12,31,"*      *    *  *     *        * *    ");
	mvprintw(13,31," ******      **      *******  *   *  ");
	mvprintw(25,31,"                                     ");
	mvprintw(26,31,"                                     ");
	mvprintw(27,31,"                                     ");
	mvprintw(28,31,"                                      ");
	mvprintw(29,31,"                                     ");
	mvprintw(30,31," Press Enter to return to main menu ");
	mvprintw(31,31,"                                     ");
	mvprintw(32,31,"                                     ");
	mvprintw(33,31,"                                     ");
	c=getch();
	while(1)														//ies la apasarea Enter
	{	if(c=='\n')
			break;
		c=getch();
	}
	
}

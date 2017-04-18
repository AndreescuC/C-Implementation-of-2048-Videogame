void menu_ART(char *user)		//functie de afisare a meniului(primeste user-ul actual ca argument)
{	mvprintw(4,52,"                                                    ");
	mvprintw(5,55,"                                              ");
	mvprintw(6,55,"                                              ");
	mvprintw(2,80,"                         ");
	attron(A_STANDOUT | A_UNDERLINE | WA_BLINK);
	mvprintw(2,80,"Welcome,%s !", user);									//mesaj de intampinare
	attroff(A_STANDOUT | A_UNDERLINE | WA_BLINK);
	
	mvprintw(4,80,"Not %s ?               ", user);							//afisare user options 
	mvprintw(5,80,"Press U to change user   ");
	mvprintw(4,70,"          ");
	mvprintw(5,70,"          ");
	curs_set(0);
	mvprintw(15,32," *****     *******   *      *   ******* ");	//2048 ASCII art
	mvprintw(16,32,"*      *  *       *  *      *  *       *");
	mvprintw(17,32,"*      *  *       *  *      *  *       *");
	mvprintw(18,32,"       *  *       *  *      *  *       *");
	mvprintw(19,32,"      *   *       *  *      *  *       *");
	mvprintw(20,32,"     *    *       *  ********   ******* ");
	mvprintw(21,32,"    *     *       *         *  *       * ");
	mvprintw(22,32,"   *      *       *         *  *       *");
	mvprintw(23,32,"  *       *       *         *  *       *");
	mvprintw(24,32," *        *       *         *  *       *");
	mvprintw(25,32," ******    *******          *   ******* ");


}

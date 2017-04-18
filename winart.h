int winf(char *s)					//intoarce resume (=1, vreau sa continui,=0,ma intorc la meniu)
{	char c;
	int resume;
	attron(COLOR_PAIR(3));
	mvprintw(12,43,"Nice job,%s!", s);
	attroff(COLOR_PAIR(3));
	mvprintw(3,15,"*               * *  ******** **********  *********   ******  *       *");
	mvprintw(4,15," *             *  * *             *      *         * *      *  *     *");
	mvprintw(5,15,"  *           *   * *             *      *         * *      *   *   *");
	mvprintw(6,15,"   *         *    * *             *      *         * *      *    * *");
	mvprintw(7,15,"    *       *     * *             *      *         * *******      *");
	mvprintw(8,15,"     *     *      * *             *      *         * * *          *");
	mvprintw(9,15,"      *   *       * *             *      *         * *  *         * ");
	mvprintw(10,15,"       * *        * *             *      *         * *   *        * ");
	mvprintw(11,15,"        *         *  ********     *       *********  *    *       *");
	mvprintw(25,33,"Press       to return to main menu ");
	mvprintw(26,34,"or     to resume and keep going");
	attron(COLOR_PAIR(3));
	mvprintw(25,39,"Enter");
	mvprintw(26,37," R ");
	attroff(COLOR_PAIR(3));
	mvprintw(27,39,"                                           ");
	mvprintw(28,39,"                                           ");
	mvprintw(29,39,"                                           ");
	mvprintw(30,39,"                                           ");
	mvprintw(31,39,"                                           ");
	mvprintw(32,39,"                                           ");
	c=getch();
	while((c!='\n') & (tolower(c)!='r'))
		c=getch();
	if(c=='\n')
		resume=0;
	if(tolower(c)=='r')
		resume=1;
		
return resume;
}

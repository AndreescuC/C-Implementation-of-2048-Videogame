#include"wrong_password.h"			//functie ce schimba user-ul
#include"new_user.h"
typedef struct user{						//foloseste structura de date continand pozitia user-ului in fisier,
	int poz;											//numele user-ului (s[20]) si parola
	char s[20];
	char parola[20];
} user;

void menu(int elem);						//va apela menu

char* change_user(char *actual)	//primeste user-ul actual
{	user v[10];
	int i,n,check=1,a=0,rookie=0;
	char c;
	char *rez;
	mvprintw(5,80,"                           ");
	mvprintw(4,80,"                         ");
	rez=malloc(40*sizeof(char));
	strcpy(rez,actual);
	init_pair(2,COLOR_BLACK,COLOR_YELLOW);
	FILE *users,*curuser;
	users=fopen("users.txt", "rw");				//deschid fisierul continand toti userii
	fscanf(users,"%d", &n);
	attron(COLOR_PAIR(2));
	for(i=0;i<=n;i++)									//eliberez ce mi-a scris functia menu_ART(ART.h)
		mvprintw(i+1,78,"                           ");
	attroff(COLOR_PAIR(2));
	for(i=0; i<n; i++)							//atribui elementelor din vectorul de tip user fiecare user in parte
	{	fscanf(users,"%s", v[i].s);		//users.txt e scris sub forma:user parola\nuser parola\n etc
		fscanf(users,"%s", v[i].parola);
		v[i].poz=i;
	}
	fclose(users);
	attron(COLOR_PAIR(2));
	for(i=0; i<n; i++)
		mvprintw(i+1,78,"%d -- %s",i,v[i].s);
	mvprintw(n+1,78,"N -- New user");
	attroff(COLOR_PAIR(2));	
	curs_set(0);
	c=getch();
	while(c==ERR)										//ma asigur ca halfdelay-ul nu-mi acceseaza portiuni de cod
		c=getch();
	while((c<48) || (c>48+n))				//valid keys:1-n(numarul de useri) sau 'N'(New user)
	{	if(tolower(c)=='n') 
			break;
		mvprintw(n+3,80," You have to press ");
		mvprintw(n+4,78,"the corresponding digit        ");
		mvprintw(n+5,79," or N for New user! ");
		c=getch();
	}
	mvprintw(n+3,80,"                       ");	//eliberez ce a fost afisat
	mvprintw(n+4,78,"                       ");
	mvprintw(n+5,79,"                        ");
	for(i=0; i<=n; i++)
		mvprintw(i+1,78,"                           ");
	if(tolower(c)=='n')
		strcpy(rez,new_user());								//apelez new_user si copiez rezultatul(numele noului user)
		
	else												//ma asigur ca daca am selectat new user, nu mai parcurg restul functiei
	{	i=(int)(c)-48;						//pozitia devine int				
		mvprintw(4,70,"Please enter your password:");
		c=getch();
		while(c==ERR)							//ma asigur ca halfdelay nu introduce caractere(ERR) in parola
			c=getch();
		a=0;							//contor pt caracterele parolei
		check=1;					//este parola corecta? 1-da,0-nu
		while(c!='\n')		//enter-am terminat parola
		{	mvprintw(5,70+a,"*");			//confirm primirea caracterului
			if(c!=v[i].parola[a])			//verificare se face caracter cu caracter
				check=0;
			a++;
			c=getch();
			while(c==ERR)
				c=getch();
		}
		if(a==0)						//elimin posibilitatea apasarii tastei Enter direct
			check=0;
		mvprintw(6,70,"%s", actual);
		if(check==0) 								//parola gresita apeleaza wrong_password
		{	if(wrong_password(v[i].s)==1)  //daca se selecteaza "Try again"
				change_user(actual);					//se reapeleaza functia
			else
				menu_ART(actual);				//daca nu,ne intoarcem la meniu
		}
		else
		{	curuser=fopen("curent_user.txt", "w");		//logare cu succes
			strcpy(rez,v[i].s);												//returnez noul username
			fprintf(curuser,"%s", v[i].s);						//suprascriu curent_user.tx
			fclose(curuser);
			strcpy(rez,v[i].s);
		}
	}	
return rez;
}

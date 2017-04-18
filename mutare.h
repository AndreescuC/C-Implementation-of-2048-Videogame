int mutare(int *a,int *b,int *c,int *d,int *score) //functia ce face mutarea a unei linii/coloane
{	int zerouri=0,valid=1;
	int ca=*a,cb=*b,cc=*c,cd=*d;		//copii pt verificarea validitatii miscarii
	if(*a==0)												//numarul de zerouri
		zerouri++;
	if(*b==0)
		zerouri++;
	if(*c==0)
		zerouri++;
	if(*d==0)
		zerouri++;
	while(*a==0)									//initial misc casetele in directia corespunzatoare
	{	if(zerouri==4)
			break;
		*a=*b;
		*b=*c;
		*c=*d;
		*d=0;
	}
	while(*b==0)
	{	if(zerouri>=3)
			break;
		*b=*c;
		*c=*d;
		*d=0;
	}
	while(*c==0)
	{	if(zerouri>=2)
			break;
		*c=*d;
		*d=0;
	}
	if(*a==*b)									//dupa mutare, alipesc unde e cazul
	{	*a=*a+*b;
		*b=*c;
		*c=*d;
		*d=0;
		*score=*score+*a;
	}
	if(*b==*c)
	{	*b=*b+*c;
		*c=*d;
		*d=0;
		*score=*score+*b;
	}
	if(*c==*d)
	{	*c=*c+*d;
		*d=0;
		*score=*score+*c;
	}
	if((ca==*a) && (cb==*b) && (cc==*c) && (cd==*d))	//verific validitatea miscarii si o intorc
		valid=0;
return valid;
}
	

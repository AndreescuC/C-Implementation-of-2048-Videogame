int locuri_libere(int a1,int b1,int c1,int d1)		//functie ce determina cate locuri libere
{	int loc=0;																			//sunt pe o linie/coloana
	if(a1==0)
		loc++;
	if(b1==0)
		loc++;
	if(c1==0)
		loc++;
	if(d1==0)
		loc++;
return loc;
}
int mutare1(int a,int b,int c,int d)				//functie ce simuleaza(nu foloseste pointeri) o mutare
{	int zerouri=0,loc=0;											//si returneaza cate locuri libere sunt dupa mutare
	if(a==0)																	//(nu cate sunt eliberate)
		zerouri++;
	if(b==0)
		zerouri++;
	if(c==0)
		zerouri++;
	if(d==0)
		zerouri++;
	while(a==0)	
	{	if(zerouri==4)
			break;
		a=b;
		b=c;
		c=d;
		d=0;
	}
	while(b==0)
	{	if(zerouri>=3)
			break;
		b=c;
		c=d;
		d=0;
	}
	while(c==0)
	{	if(zerouri>=2)
			break;
		c=d;
		d=0;
	}
	if(a==b)
	{	a=a+b;
		b=c;
		c=d;
		d=0;
	}
	if(b==c)
	{	b=b+c;
		c=d;
		d=0;
	}
	if(c==d)
	{	c=c+d;
		d=0;
	}
	loc=locuri_libere(a,b,c,d);
return loc;
}
int auto_move(int *v,int a,int b,int c,int d)					//functie ce simuleaza(foloseste copii)
{	int a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3,a4,b4,c4,d4;//toate cele 4 mutari(fiecare a cate 4 apeluri
	int jos=0,sus=0,stanga=0,dreapta=0,max=0,rez=0;			//a functiei mutare1)
	a1=v[0];b1=v[1];c1=v[2];d1=v[3];
	a2=v[4];b2=v[5];c2=v[6];d2=v[7];
	a3=v[8];b3=v[9];c3=v[10];d3=v[11];
	a4=v[12];b4=v[13];c4=v[14];d4=v[15];
	jos=mutare1(a4,a3,a2,a1)+mutare1(b4,b3,b2,b1)+mutare1(c4,c3,c2,c1)+mutare1(d4,d3,d2,d1);
	if((jos>max) && (a==1))
	{	max=jos;
		rez=1;
	}
	sus=mutare1(a1,a2,a3,a4)+mutare1(b1,b2,b3,b4)+mutare1(c1,c2,c3,c4)+mutare1(d1,d2,d3,d4);
	if((sus>max) && (b==1))
	{	rez=2;
		max=sus;
	}
	stanga=mutare1(d1,c1,b1,a1)+mutare1(d2,c2,b2,a2)+mutare1(d3,c3,b3,a3)+mutare1(d4,c4,b4,a4);
	if((stanga>max) && (c==1))
	{	rez=3;
		max=stanga;
	}
	dreapta=mutare1(a1,b1,c1,d1)+mutare1(a2,b2,c2,d2)+mutare1(a3,b3,c3,d3)+mutare1(a4,b4,c4,d4);
	if((dreapta>max) && (d==1))
	{	rez=4;
		max=dreapta;
	}
return rez;											//dupa cele 4 simulari, determina care ar elibera cele mai multe casute
}										//returneaza 1-jos,2-sus,3-stanga sau 4-dreapta
	
	

typedef struct scor_struct{
	char user[20];
	int score;
}scor_struct;
//#include"scor_struct.h"

void sregister(char *user,int newscore)		//inregistrez scorul sub forma user scor
{	FILE *file;
	int i,n,aux,j;
	char saux[20];
	scor_struct v[50];
	file=fopen("highscores.txt","r");
	fscanf(file,"%d", &n);
	for(i=0;i<n;i++)
	{	fscanf(file,"%s",v[i].user);
		fscanf(file,"%d", &v[i].score);
	}
	strcpy(v[n].user,user);
	v[n].score=newscore;
	fclose(file);
	for(i=0; i<n; i++)					//le ordonez
		for(j=i+1; j<=n; j++)
			if(v[j].score>v[i].score)
			{	aux=v[i].score;
				v[i].score=v[j].score;
				v[j].score=aux;
				strcpy(saux,v[i].user);
				strcpy(v[i].user,v[j].user);
				strcpy(v[j].user,saux);
			}
	
	file=fopen("highscores.txt","w");
	
	if(n+1<=10)											//retin maxim 10 scoruri
	{	fprintf(file,"%d\n", n+1);
		for(i=0; i<=n; i++)
			fprintf(file,"%s %d\n", v[i].user,v[i].score);
		
	}
	else
	{	fprintf(file,"%d\n",n);
		for(i=0; i<10; i++)
				fprintf(file,"%s %d\n", v[i].user,v[i].score);
	}
	fclose(file);
}
	

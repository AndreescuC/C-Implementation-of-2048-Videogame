char* get_user()					//citeste din curent_user.txt user-ul actual(ultimul logat)
{	char *s;
	s=malloc(20*sizeof(char));
	FILE *file;
	file=fopen("curent_user.txt","r");
	fscanf(file,"%s", s);
	fclose(file);
return s;
}    	
	

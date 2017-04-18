void track_of_score(int *score,int indicator)			//functie ce scrie scorul actual(indicator=0)
{	FILE *file;																			//sau il scrie (indicator=1)
	int a;
	if(indicator==0)
	{	file=fopen("track_of_score.txt", "w");
		fprintf(file,"%d\n", *score);
	}
	else
	{	file=fopen("track_of_score.txt", "r");
		fscanf(file,"%d", &a);
		*score=a;
	}
	fclose(file);
}

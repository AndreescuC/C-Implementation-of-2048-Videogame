void progress_save(int import_export,int *v)		//salvez progresul in fisier
{	FILE *file;																	//variabila import_export imi spune daca vreau sa
	int i,scor=0;															//inregistrez valorile (le scriu in fisier)
	if(import_export==0)									//sau sa le accesez/citesc(pt resume)
	{	file=fopen("progress.txt", "w");
		for(i=0; i<16; i++)
			fprintf(file,"%d\n", v[i]);
		
		
	}
	else
	{	file=fopen("progress.txt", "r");
		for(i=0; i<16; i++)
			fscanf(file,"%d", &v[i]);
		
		
	}
	fclose(file);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compressFile(const char *inputFile,const char *outputFile)
{
	FILE *in= fopen(inputFile,"r");
	FILE *out= fopen(outputFile,"w");
	
	if(in==NULL || out==NULL)
	{
	printf("Error opening files!\n");
	return;
    }
    
    char ch,prev;
    int count=1;
    
    prev=fgetc(in);//Read the first character
    if(prev==EOF)
    {
    	fclose(in);
    	fclose(out);
    	return;
	}
	
	//Read each character from the file
	while((ch=fgetc(in))!=EOF)
	{
		if(ch==prev)
		{
			count++;
		}
		else
		{
			//Write the previous character and its count
			fprintf(out,"%c%d",prev,count);
			prev=ch;
			count=1;
		}
	}
	//Write the last character and count
	fprintf(out,"%c%d",prev,count);
	fclose(in);
	fclose(out);
	printf("File compressed successfully.\n");
}

void decompressFile(const char *inputFile, const char *outputFile)
{
	FILE *in= fopen(inputFile,"r");
	FILE *out= fopen(outputFile,"w");
	
	if(in==NULL || out==NULL)
	{
	printf("Error opening files!\n");
	return;
    }
    
    char ch;
    int count;
    
    //Read character and number from compressed file
    while((ch=fgetc(in))!=EOF)
    {
    	if(fscanf(in,"%d",&count)!=1)
    	{
    		printf("Error reading count.\n");
    		break;
		}
		
		//Write the character 'count' times to decompressed file
		for(int i=0;i<count;i++)
		{
			fputc(ch,out);
		}
	}
	fclose(in);
	fclose(out);
	printf("File decompressed successfully.\n");
}

int main()
{
	int choice;
	char inputFile[100],outputFile[100];
	
	while(1)
	{
     printf("\n--------------------------\n");
	printf("1.Compress a file.\n");
	printf("2.Decompress a file.\n");
	printf("3.Exit.\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
	if(choice==3)
	{
		printf("Exiting the program.\n");
		break;
	}
	printf("Enter input file name: ");
	scanf("%s",inputFile);
	printf("Enter output file name:");
	scanf("%s",outputFile);
	
	if(choice==1)
	{
		compressFile(inputFile,outputFile);
	}
	else if(choice==2)
	{
		decompressFile(inputFile,outputFile);
	}
	else
	{
		printf("Invalid choice.Please try again.");
	}
   }
	return 0;
}

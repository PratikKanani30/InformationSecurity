#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int key,choice,count=0;
	FILE *fi,*fo,*fo2;
	char ch,ch1;
	clrscr();
	printf("\nEnter the Key :");
	scanf("%d",&key);
		fi=fopen("plain.txt","r");
		fo=fopen("cipher.txt","w");
		printf("\nYour plain text is :");
		while((ch=fgetc(fi))!=EOF)
		{
			printf("%c",ch);
		if(ch==(' '))
			fputc(ch,fo);
		else if(65<=ch && ch<=90)
			fputc(((ch-65+key)%26+65),fo);
		else if(97<=ch && ch<=122)
			fputc(((ch-97+key)%26+97),fo);
		else
			fputc(ch,fo);
		}
		printf("\n\n:ENCRYPTION:");
		printf("\nYour Plain text is converted successfully into cipher  
            text");
		fclose(fi);
		fclose(fo);

		fo=fopen("cipher.txt","r");
		fo2=fopen("decry.txt","w");
		printf("\nYour cipher text is :");
		while((ch=fgetc(fo))!=EOF)
		{
			printf("%c",ch);
		if(ch==(' '))
			fputc(ch,fo2);
		else if(65<=ch && ch<=90)
			fputc(((ch-65-key+26)%26+65),fo2);
		else if(97<=ch && ch<=122)
			fputc(((ch-97-key+26)%26+97),fo2);
		else
			fputc(ch,fo2);
		}
		printf("\n\n:DCRYPTION:");
		printf("\nYour cipher text is converted successfully into plain 
            text");
		fclose(fo);
		fclose(fo2);
		//checking
		fi=fopen("plain.txt","r");
		fo2=fopen("decry.txt","r");
		printf("\nYour dicrypted text : ");
		while(((ch=fgetc(fi))!=EOF)&&((ch1=fgetc(fo2))!=EOF))
		{
		   printf("%c",ch1);
		   if(ch!=ch1)
		   {		     
		     count++;
		   }
		}
		if(count==0)
		   printf("\n\nYour conversion is Correct");
            else
               printf("\n\nYour conversion is Incorrect");


	getch();

}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int choice,count=0,i=0;
	FILE *fi,*fo,*fo2,*fk;
	char ch,ch1,key[52];
	char *pos;
	clrscr();

		fi=fopen("plain.txt","r");
		fo=fopen("cipher.txt","w");
		fk=fopen("key.txt","r");
		printf("Your key file is : ");
		while((ch=fgetc(fk))!=EOF)
		{
		     printf("%c",ch);
		     key[i]=ch;
		     i++;
		}

		printf("\n\nYour plain text is :");
		while((ch=fgetc(fi))!=EOF)
		{
			printf("%c",ch);
		if(ch==(' '))
			fputc(ch,fo);
		else if(65<=ch && ch<=90)
			fputc(key[ch-65+26],fo);
		else if(97<=ch && ch<=122)
			fputc(key[ch-97],fo);
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
		{
			pos=strchr(key,ch);
			fputc(pos-key+65-26,fo2);
		}
		else if(97<=ch && ch<=122)
		{
			pos=strchr(key,ch);
			fputc(pos-key+97,fo2);
		}
		else
			fputc(ch,fo2);
		}
		printf("\n\n:DCRYPTION:");
		printf("\nYour cipher text is converted successfully into plain 
            text");
		fclose(fo);
		fclose(fo2);
		fclose(fk);

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
		   printf("\n\nYour conversion is InCorrect");

	getch();
}

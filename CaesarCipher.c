#include<stdio.h>
#include<conio.h>

void main()
{
	int key=3;
	FILE *fi,*fo;
	char ch;
	clrscr();
	fi=fopen("plain.txt","r");
	fo=fopen("cipher.txt","w");
	printf("Key is : %d",key);
	printf("\n\nYour plain text is : ");

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
	fclose(fi);
	fclose(fo);

	fo=fopen("cipher.txt","r");
	printf("\nYour cipher text is : ");
	while((ch=fgetc(fo))!=EOF)
	{
	       printf("%c",ch);
	}
	fclose(fo);

	printf("\n\nplain text is converted successfully to cipher text");
	getch();

}

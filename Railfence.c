#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<string.h>
void main()
{
	FILE *fi,*fo,*fo2;
	char ch,ch1,si[100],so[100],si2[100],so2[100];
	int i,j=0,k,rf,t=0,q=0,n,count=0;
	clrscr();
	printf("Enter the Depth of RF : ");
	scanf("%d",&rf);
	fi=fopen("plain.txt","r");
	fo=fopen("cipher.txt","w");
	printf("\nYour plain text is : ");
	ch=getc(fi);
	while(ch!=EOF)
	{
		printf("%c",ch);
		if(ch==' ')
			si[q]='!';
		else
			si[q]=ch;
		q++;
		ch=getc(fi);
	}

	if(q%rf!=0)
	{
		t=q%rf;
		t=rf-t;
		for(i=0;i<t;i++)
		{
			si[q]='?';
			q++;
		}
	}
	printf("\n\n");
	si[q]='\0';
	for(i=0;i<rf;i++)
	{
		for(k=i;k<q;k=k+rf)
		{
			so[j]=si[k];
			j++;
			printf("%c ",si[k]);

		}
		printf("\n");
	}
	so[q]='\0';
	printf("\n: Encryption : ");
	printf("\nYour plain text is converted successfully into cipher
      text");
	printf("\nYour cipher text is : ");
	for(i=0;so[i]!='\0';i++)
	{
		fputc(so[i],fo);
		printf("%c",so[i]);
	}
	fclose(fi);
	fclose(fo);

	fo=fopen("cipher.txt","r");
	fo2=fopen("decry.txt","w");
	printf("\n \n");
	q=0;
	ch=getc(fo);
	while(ch!=EOF)
	{
		si2[q]=ch;
		q++;
		ch=getc(fo);
	}
	n=q/rf;
	for(i=0,j=0;i<n;i++)
	{
		for(k=i;k<q;k=k+n)
		{
			if(si2[k]!='?')
			{
				so2[j]=si2[k];
				j++;
			}
		}
	}
	printf("\n : Decryption : ");
	printf("\nYour cipher text is converted successfully into plain 
      text");
	for(i=0;i<j;i++)
	{
		if(so2[i]=='!')
		   fputc(' ',fo2);
		else
		   fputc(so2[i],fo2);
	}
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
	       printf("\n\nYour conversion is InCorrect");

	getch();
}

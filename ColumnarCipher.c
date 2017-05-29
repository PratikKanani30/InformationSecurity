#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<string.h>
void main()
{
	FILE *fi,*fo,*fo2;
	char ch,ch1,si[100],so[100],si2[100],so2[100];
	int i,j=0,k=0,t,q=0,n,count=0,*key,*d;
	clrscr();
	printf("Enter the key array length : ");
	scanf("%d",&n);
	printf("\n:: Enter the key array ::\n");
	for(i=0;i<n;i++)
	{
	   printf("key[%d] : ",i);
	   scanf("%d",&key[i]);
	   if(key[i]>n-1)
	   {
	      printf("\nThis value is not valid ");
	      i--;
	   }
	}
	fi=fopen("plain.txt","r");
	fo=fopen("cipher.txt","w");
	printf("\nYour original is : ");
	ch=getc(fi);
	while(ch!=EOF)
	{
		printf("%c",ch);
		if(ch==' ')
			si[q]='%';
		else
			si[q]=ch;
		q++;
		ch=getc(fi);
	}

	if(q%n!=0)
	{
		t=q%n;
		t=n-t;
		for(i=0;i<t;i++)
		{
			si[q]='#';
			q++;
		}
	}
	si[q]='\0';
	printf("\nYour plain text is : ");
	for(i=0;i<q;i++)
	{
		printf("%c",si[i]);
		if(j>=n)
		{
		j=0;
		k=k+n;
		}
		so[i]=si[k+key[j]];
		j++;
	}
	so[q]='\0';
	printf("\n\n: Encryption : ");
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
	ch=getc(fo);
	q=0;
	while(ch!=EOF)
	{
		si2[q]=ch;
		q++;
		ch=getc(fo);
	}
	for(i=0;i<n;i++)
	{
	      d[key[i]]=i;
	}
	printf(": Decryption : ");
	printf("\nYour cipher text is converted successfully into plain 
      text");
	for(i=0,k=0,j=0;i<q;i++)
	{
		if(j>=n)
		{
		j=0;
		k=k+n;
		}
		so2[i]=si2[k+d[j]];
		j++;
		if(so2[i]=='%')
		  so2[i]=' ';
		if(so2[i]!='#')
		  putc(so2[i],fo2);
	}
	so2[q]='\0';
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

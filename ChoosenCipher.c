#include<stdio.h>
#include<conio.h>
#include<math.h>
long power(long,long,long);
long extended_euclid(long m,long b)
{
	long a1=1,a2=0,a3=m,b1=0,b2=1,b3=b,q=0,t1,t2,t3;
	abc:
	if(b3==0)
	{
		return 0;
	}
	if(b3==1)
	{
		return b2;
	}
	q=a3/b3;

	t1=a1-q*b1;
	t2=a2-q*b2;
	t3=a3-q*b3;

	a1=b1;
	a2=b2;
	a3=b3;

	b1=t1;
	b2=t2;
	b3=t3;

	goto abc;
	a:
	return 0;
}
void main()
{
	long p,q,n,m,fn,e,c,d,x,y,y1,z;
	clrscr();
	printf("enter msg:=");
	scanf("%ld",&m);
	printf("\nenter any two prime numbers:=\n");
	scanf("%ld %ld",&p,&q);
	n=p*q;
	fn=(p-1)*(q-1);
	printf("\nenter the value of e which is relatively prime to %ld:=\n",fn);
	scanf("%ld",&e);
	c=power(m,e,n);
	printf("\nencrypted msg is:=%ld",c);
	printf("\nenter value of x:=");
	scanf("%ld",&x);
	y1=power(x,e,n);
	y=(y1*c)%n;
	printf("\ny:=%ld",y);
	d=extended_euclid(fn,e);
	if(d<0)
		d=d+fn;
	printf("\nd:=%ld",d);
	m=power(c,d,n);
	printf("\ndecrypted msg is:=%ld",m);
	z=power(y,d,n);
	printf("\ndecription for tom:=%ld",z);
	m=(z*extended_euclid(n,x))%n;
	if(m<0)
		m=m+n;
	printf("\nfinal dec for tom:=%ld",m);
	getch();
}
long power(long a,long b,long n)
{
	long ans=a,i;
	for(i=0;i<b-1;i++)
	{
		ans=ans%n;
		ans=ans*a;
	}
	return(ans%n);
}

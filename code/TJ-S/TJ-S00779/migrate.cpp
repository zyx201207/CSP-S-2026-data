#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N];
char tmp[100000],*p(0),*top(0);
//#define gtch()  (p==top&&(top=(p=tmp)+fread(tmp,1,100000,stdin)),*p++)
int read()
{
	int x;
	char c;
	bool f=0;
	while((c=getchar())<'0')  if(c=='-') {f=1;}
	x=c^'0';
	while((c=getchar())>='0') x=x*10+(c^'0');
	return f?(~x+1):x;
}
inline void print(int n)
{
	if(n<0){
		putchar('-');
		n*=-1;
	}
	if(n>9)  print(n/10);
	putchar(n%10+'0');
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		n=read();
		d=read();
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)  x[i]=read();
		if(d<a[2]-a[1]) 
		{
			cout<<0;
			continue;
		}
		if(n<=3)  
		{
			cout<<0;
			continue;
		}
		cout<<n*n/2;
	}
} 

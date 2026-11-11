#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N];
int read()
{
	int a=0,b=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') b*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
signed main()
{
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
		}
		
	}
}
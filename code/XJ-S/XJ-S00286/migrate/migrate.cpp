#include <bits/stdc++.h>
using namespace std;
const int N=2e6+12;
long long c,t,n;
long long d,x[N];
long long read()
{
	char k=getchar();
	int f=1;
	long long s=0;
	if(k=='-')
	{
		f=-1;
		k=getchar();
	}
	while(k>='0'&&k<='9')
	{
		s*=10;
		s+=k-'0';
		k=getchar();
	}
	return s*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	if(c==11||c==12)
	{
		t=read();
		while(t--)
		{
			n=read();
			d=read();
			for(int i=1;i<=n;i++)
			{
				x[i]=read();
			}
			long long dx=x[2]-x[1];
			if(d<=dx)
			{
				cout<<0<<endl;
				continue;
			}
			long long num=floor(d/dx*1.0);
			if(num==1)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				long long num1=num*2-1;
				if(num1>=n)
				{
					cout<<0<<endl;
					continue;
				}
				cout<<n-num1<<endl;
				continue;
			}
		}
	}
	return 0;
}

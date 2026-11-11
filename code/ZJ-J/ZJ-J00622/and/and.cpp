#include<bits/stdc++.h>
using namespace std;
int cmd(int a,int b)
{
	if (a>b)
		return 1;
	return 0;
}

long long x[200001],y[200001][31];
void f(long long a,long long b)
{
	for (long long i=1;i<=b;i++)
		if (y[i][a]==0)
			x[i]=1;
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  a,b,c,d,s;
	cin>>a>>b;
	memset(y,0,sizeof(y));
	memset(x,0,sizeof(x));
	for (long long i=1;i<=a;i++)
		cin>>x[i];
	sort(x+1,x+a+1,cmd);
	for (long long i=1;i<=a;i++)
	{
		long long j=0;
		while (x[i]!=0)
		{
			if (x[i]%2==1)
				y[i][j]=1;
			else
				y[i][j]=0;
			j++;
			x[i]/=2;
		}
		c = max(c,j);
	}
	memset(x,0,sizeof(x));
	for (long long i=c;i>=0;i--)
	{
		s*=2;
		d = 0;
		for (long long j=1;j<=a;j++)
		{
			if (y[j][i]==1&&x[j]==0)
				d+=1;				
		}
		if (d>=b)
		{
			s++;
			f(i,a);
		}
	}
	cout<<s;
	return 0;
}

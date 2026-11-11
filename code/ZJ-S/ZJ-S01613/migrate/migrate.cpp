#include<bits/stdc++.h>
using namespace std;
long long a[2000005],d,q;
int n,s;
void df(int x,int y,int w)
{
	if(x==y)
	{
		if(w==s)
		{
			q++;
		}
		if(w<s)
		{
			q=1;
			s=w;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]>d)
		{
			break;
		}
		df(i,y,w+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long f=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=n+1;
				q=0;
				df(i,j,0);
				if(q==2)
				{
					f++;
				}
			}
		}
		cout<<f<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
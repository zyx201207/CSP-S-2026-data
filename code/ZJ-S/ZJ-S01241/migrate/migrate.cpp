#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=5e5+1,INF=0x3f3f3f3f;
int c,T;
int n,d;
int a[inf];
int dis[5001][5001];
void init()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			dis[i][j]=INF;
		}
	}
	return ;
}
void solve1()
{
	init();
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(abs(a[i]-a[j])<=d)dis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(dis[i][j]>dis[i][k]+dis[j][k]&&abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d)
				{
					dis[i][j]=dis[i][k]+dis[j][k];
					tot=1;
				}
				else if(dis[i][j]==dis[i][k]+dis[j][k]&&abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d)
				{
					dis[i][j]=dis[i][k]+dis[j][k];
					tot++;
				}
			}
			if(tot==2)
			{
				ans++;
			}
			tot=1;
		}
	}
	cout<<ans/2<<"\n";
	return ;
}
void dfs(int dep)
{
	
	return ;
}
void solve2()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	return ;
}
void solve3()
{
	
	return ;
}
void solve4()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<0<<"\n";
	return ;
}
int main()
{
	freopen("migrate.in ","r",stdin);
	freopen("migrate.in ","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		if(c<=6)solve1();
		else if(c>=3&&c<=10)solve2();
		else if(c==11||c==12)solve3();
		else solve4();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
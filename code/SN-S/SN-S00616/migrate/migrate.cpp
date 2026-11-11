#include<bits/stdc++.h>
using namespace std;
//#define int long long 
//int mian()
int c,t,n,d,island[305],nin=0x3f3f3f,ans,ns;
void dfs(int now,int zb,int stp)
{
	for(int i=now+1;i<=n;i++)
	{
		if(island[i]-island[now]<=d)dfs(i,island[i],stp+1);
	}
	if(now==n)
	{
		if(stp<nin){
			nin=stp;
			ans=1;
		}else if(stp=nin)ans++;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>island[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				nin=0x3f3f3f;
				dfs(i,island[i],1);
				if(ans==2)ns++;
			}
		}
		cout<<ns<<endl;
	}
	return 0;
}
/*
Give me 10 points
*/


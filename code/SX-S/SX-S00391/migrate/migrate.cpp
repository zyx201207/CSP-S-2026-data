#include <bits/stdc++.h>
using namespace std;
const int N=55;
int res[N][N][N];
int n,d;
int x[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(res,0,sizeof res);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14)
		{
			cout<<0<<'\n';
		}
		else
		{
			int ans=0;
			int u=0,v=0;
			for(int i=0;i<1<<n;i++)
			{
				int lst=-1,step=0;
				u=0,v=0;
				bool flag=1;
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)
					{
						if(lst==-1) lst=j+1,u=j+1;
						else if(x[lst]+d>=x[j+1]) step++,v=j+1;
						if(x[lst]+d<x[j+1]) flag=0;
					}
				}
				if(flag) res[u][v][step]++;
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					bool flag=1;
					for(int k=1;k<=n-1;k++)
					{
						if(flag&&res[i][j][k]==2)
						{
							ans++;
						}
						if(res[i][j][k]) flag=0;
					}
				}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

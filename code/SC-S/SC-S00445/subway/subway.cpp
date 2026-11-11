#include<bits/stdc++.h>
using namespace std;
int m;
int n;
int c,d,q;
int t[505][500005];//第i条线路时j的站厅到站台的时间 
int k[505];//第i条线路经过k[i]个站 
int w[10000005];//站台到地铁站的时间 
int a[505][500005];//第i条线路 的第j个站是a[i][j] 
int v[500005][505];//第i个站有v[i][1],v[i][2],...,v[i][num[i]]的线路经过
int num[500005];
int st,en;//起点，终点 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ios::sync_with_stdio(false),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			v[a[i][j]][++num[a[i][j]]]=i;
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>st>>en;
		int ans=10000;
		if(c>=1&&c<=3)
		{
			for(int j=1;j<=num[st];j++)
			{
				for(int p=1;p<=k[j];p++)
				{
					if(a[j][p]==en)
					{
						ans=min(ans,w[st]+w[en]+t[j][st]+t[j][en]);
					}
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(j!=st&&j!=en&&num[j]==2)
				{
					if(v[st][1]==1)
						ans=min(ans,w[st]+w[en]+t[1][st]+t[1][j]+t[2][en]+t[2][j]);
					else
						ans=min(ans,w[st]+w[en]+t[2][st]+t[2][j]+t[1][en]+t[1][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
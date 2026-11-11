#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define PII pair<int,int> 
using namespace std;
const ll M=1e18;
int c,n,m,d,q;
vector<PII>v[500007];
ll vis[507][507],f[507][507];
int w[500007];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IO;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[i][j]=f[i][j]=M;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		vis[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(v[i].size()>=2)
		{
			for(int j=0;j<v[i].size();j++)
			{
				for(int k=0;k<v[i].size();k++)
				{
					if(j==k) continue;
					int st1=v[i][j].first,st2=v[i][k].first,val1=v[i][j].second,val2=v[i][k].second;
					vis[st1][st2]=vis[st2][st1]=min(vis[st1][st2],1ll*val1+val2);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=vis[i][j];
	//		cout<<vis[i][j]<<" ";
		}
	//	cout<<endl;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]!=M&&f[k][j]!=M)
				{
					f[i][j]=min(f[k][j]+f[i][k],f[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,en;
		ll ans=1e18;
		cin>>st>>en;
		for(int j=0;j<v[st].size();j++)
		{
			for(int k=0;k<v[en].size();k++)
			{
				if(f[v[st][j].first][v[en][k].first]!=M)
					ans=min(ans,f[v[st][j].first][v[en][k].first]+w[st]+w[en]+v[st][j].second+v[en][k].second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

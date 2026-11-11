// 门可铭 辅轮中学 SN-S00441
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[510],tot,ans[510][510],mp[5010][5010];
vector<pair<int,int>> G[600010];
void solve()
{
	memset(mp,0x3f,sizeof mp);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	tot=m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int a,t;
			cin>>a>>t;
			G[++tot].push_back({a,t});
			G[a].push_back({tot,t});
			mp[tot][a]=t;
			mp[a][tot]=t;
			if(i>1)
			{
				mp[tot][tot-1]=mp[tot-1][tot]=0;
				G[tot].push_back({tot-1,0});
				G[tot-1].push_back({tot,0});
			}
		}
	}
	
	for(int k=1;k<=tot;k++)
	for(int i=1;i<=tot;i++)
	for(int j=1;j<=tot;j++)
	{
		mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<mp[x][y]+w[x]+w[y]<<'\n';
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,d,x,y,ans,w_[500005],g[505][505];
vector<long long>cnt[500005];
vector<long long>w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>c>>q;
	for(int i=1;i<=m;i++)cin>>w_[i];
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		while(d--)
		{
			cin>>x>>y;
			cnt[x].push_back(i);
			w[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)g[i][j]=g[j][i]=0x0fffffffffffffff;
	for(int id=1;id<=m;id++)
	if(cnt[id].size()>1)
	for(int i=0;i<cnt[id].size();i++)
	for(int j=0;j<cnt[id].size();j++)
	g[cnt[id][i]][cnt[id][j]]=min(g[cnt[id][i]][cnt[id][j]],w[id][i]+w[id][j]);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=min(g[i][j],g[i][k]+g[j][k]);
	while(q--)
	{
		cin>>x>>y;
		ans=0x0fffffffffffffff;
		for(int i=0;i<cnt[x].size();i++)
		for(int j=0;j<cnt[y].size();j++)
		ans=min(ans,g[cnt[x][i]][cnt[y][j]]+w[x][i]+w[y][j]);
		cout<<ans+w_[x]+w_[y]<<'\n';
	}
	return 0;
}

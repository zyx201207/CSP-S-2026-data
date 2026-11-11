#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500010],dis[510][510];
vector<ll>t[500010],wh[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	int cid,n,m,d,q;
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int id;
			ll ti;
			cin>>id>>ti;
			for(int j=0;j<t[id].size();j++){
				dis[wh[id][j]][i]=min(dis[wh[id][j]][i],t[id][j]+ti);
				dis[i][wh[id][j]]=dis[wh[id][j]][i];
			}
			t[id].push_back(ti);
			wh[id].push_back(i);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		ll as=1e18;
		cin>>x>>y;
		for(int i=0;i<t[x].size();i++){
			for(int j=0;j<t[y].size();j++){
				// cout<<wh[x][i]<<' '<<wh[y][j]<<' '<<dis[wh[x][i]][wh[y][j]]<<' '<<t[x][i]<<' '<<t[y][i]<<'\n';
				as=min(as,dis[wh[x][i]][wh[y][j]]+t[x][i]+t[y][j]);
			}
		}
		cout<<as+w[x]+w[y]<<'\n';
	}
	return 0;
}
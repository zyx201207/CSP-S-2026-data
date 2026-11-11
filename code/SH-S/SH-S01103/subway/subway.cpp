#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
const int N=5e5+9,M=509;
const int inf=1e18;
int cid,n,m,d,q,usl[N],dis[M][M];
vector <pii> tw[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>usl[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			tw[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		int nm=tw[i].size();
		for(int j=0;j<nm;j++)
			for(int k=0;k<nm;k++)
				dis[tw[i][j].x][tw[i][k].x]=min(dis[tw[i][j].x][tw[i][k].x],tw[i][j].y+tw[i][k].y);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(int i=0;i<tw[u].size();i++)
			for(int j=0;j<tw[v].size();j++)
				ans=min(ans,tw[u][i].y+tw[v][j].y+dis[tw[u][i].x][tw[v][j].x]);
		cout<<ans+usl[u]+usl[v]<<'\n';
	}
	return 0;
}

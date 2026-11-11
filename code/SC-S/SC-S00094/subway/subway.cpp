#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define fop(i,l,r) for(int i=l;i<=r;i++)
int dc,n,m,d,q,dis[505][505],w[500005];
vector<PII>ls[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>dc>>n>>m>>d>>q;fop(i,1,m)cin>>w[i];
	fop(i,1,n){
		int x;cin>>x;fop(j,1,x){
			int u,w;cin>>u>>w;
			ls[u].push_back({i,w});
		}
	}fop(i,1,n)fop(j,1,n)if(i!=j)dis[i][j]=1e18;
	for(int i=1;i<=m;i++){
		for(PII&a:ls[i])for(PII&b:ls[i])dis[a.fi][b.fi]=min(dis[a.fi][b.fi],a.se+b.se);
	}fop(k,1,n)fop(i,1,n)fop(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=1e18;cin>>x>>y;
		for(PII&a:ls[x])for(PII&b:ls[y])ans=min(ans,a.se+b.se+dis[a.fi][b.fi]);
		cout<<ans+w[x]+w[y]<<'\n';
	}return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
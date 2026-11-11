#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int n,m,c,d,q,dis[N][N],w[M];
vector<pair<int,int>>st[M];
void add(int u,int v,int w){dis[u][v]=dis[v][u]=min(dis[u][v],w);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,x,t;cin>>k;
		while(k--) cin>>x>>t,st[x].push_back(make_pair(i,t));
	}
	for(int i=1;i<=m;i++)
		for(auto a:st[i])
			for(auto b:st[i])
				add(a.first,b.first,a.second+b.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int s,t,ans=inf;cin>>s>>t;
		for(auto a:st[s])
			for(auto b:st[t])
				ans=min(ans,a.second+b.second+dis[a.first][b.first]);
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}


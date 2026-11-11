#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=510,M=5e5+10;
int C,n,m,d,q,an[M],dis[N][N];
vector<pair<int,int> > vec[N],e[M];

void solve(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>an[i];
	for(int u=1;u<=n;u++){
		int k,v,w;
		cin>>k;
		while(k--){
			cin>>v>>w;
			vec[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int u=1;u<=n;u++){
		for(pair<int,int> p:vec[u]){
			int i=p.first,w1=p.second;
			for(pair<int,int> q:e[i]){
				int v=q.first,w2=q.second;
				int w=w1+w2;
				dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=2000000000000000000;
		cin>>x>>y;
		for(pair<int,int> p:e[x]){
			for(pair<int,int> q:e[y]){
				int u=p.first,w1=p.second;
				int v=q.first,w2=q.second;
				ans=min(ans,dis[u][v]+w1+w2);
			}
		}
		ans+=an[x]+an[y];
		cout<<ans<<"\n";
	}
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}


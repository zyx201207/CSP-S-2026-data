#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Cosmic{
	void fre(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	const int N=5e5+10,inf=1e18;
	int f[N],ans=inf,w[N],k[N],a[30][N],t[30][N];
	struct edge{
		int x,y;
	};
	vector<edge> e[N];
	void dfs(int now,int end,int tm,int types){
		if(f[now]) return ;
		f[now]=1;
		if(now==end) {
			ans=min(ans,tm);
			return ;
		}
		for(auto u:e[now]) {
			if(u.x==types) dfs(a[u.x][u.y],end,tm,u.x);
			else dfs(a[u.x][u.y],end,tm+t[u.x][u.y-1]+t[u.x][u.y]+w[now],u.x);
		}
	}
	void solve(){
		int n,m,d,q,c;
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++) {
				cin>>a[i][j]>>t[i][j];
				if(j>1){
//					e[a[i][j]].push_back((edge){a[i][j-1],t[i][j],i});
					e[a[i][j-1]].push_back((edge){i,j});
				}
			}
		}
		while(q--){
			int s,t; cin>>s>>t;
			ans=inf;
			dfs(s,t,0,0);
			cout<<ans+w[t]<<'\n';
			memset(f,0,sizeof f);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Cosmic::fre();
	int T=1;
	while(T--) Cosmic::solve();
}

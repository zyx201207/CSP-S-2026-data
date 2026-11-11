#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
struct node{
	int v,w;
};
int c,t,n,d,x[N],dis[N],cnt,ans,minn;
vector<int> g[N];
inline void dfs(int x,int to,int s){
	if(x==to){
		if(s<minn) cnt=0,minn=s;
		if(s==minn) cnt++;
		return;
	}
	for(int i=0;i<(int)g[x].size();i++){
		int now=g[x][i];
		dfs(now,to,s+1);
	}
}
inline void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
			}else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0,minn=inf;
			dfs(i,j,0);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IO;
	cin>>c>>t;
	while(t--) solve();

	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
//#define popcnt __builtin_popcount
const int N=2e6+5;
int d[N],n,c,t,k;
vector<int>g[N];
int far,cc;
void dfs(int u,int fa){
	for(int v:g[u]){
		if(v==fa)continue;
	
		d[v]=d[u]+1;
		if(d[v]>cc){
			cc=d[v];
			far=v;
		}
		dfs(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	d[far]=0;
	dfs(far,0);
	cout<<d[far]/2<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m;
int a[N];
multiset<int> d;
int minn;
void dfs(int u,int dst,int dis){
	if(u==dst){
		minn=min(minn,dis);
		d.insert(dis);
		return;
	}
	for(int v=u+1;v<=dst;v++){
		if(a[v]-a[u]>m) break;
		dfs(v,dst,dis+1);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d.clear();
			minn=2e9;
			dfs(i,j,0);
			ans+=(d.count(minn)==2);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*

*/
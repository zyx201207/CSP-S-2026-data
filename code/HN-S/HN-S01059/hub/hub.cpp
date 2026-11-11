#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,k;
int fs[1000005],to[1000005],nx[1000005],tot;
bool f[1000005];

void dfs(int i,int x){
	if(x>n){
		ans=min(ans,check());
		return;
	}
	f[i]=1;
	dfs(i+1,x+1);
	f[i]=0;
	dfs(i+1,x);
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		tot++,to[tot]=v,nx[tot]=fs[u],fs[u]=tot;
		tot++,to[tot]=u,nx[tot]=fs[v],fs[v]=tot; 
	}
	dfs(1,0);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

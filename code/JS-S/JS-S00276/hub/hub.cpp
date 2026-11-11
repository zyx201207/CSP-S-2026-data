#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ins insert
#define int long long
#define pii pair<long long,long long>
#define endl "\n"
int c,T,n,k,dep[100012],maxSpot=0,rt;
vector<int>e[100012];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[maxSpot])maxSpot=u;
	for(int v:e[u])if(v!=fa)dfs(v,u);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>T;
    for(;T;T--){
		cin>>n>>k;
		rep(i,1,n)e[i].clear();
		rep(i,1,n-1){
			int u,v;cin>>u>>v;
			e[u].pb(v);e[v].pb(u);
		}
		dfs(1,0);
		rt=maxSpot;maxSpot=0;
		dfs(rt,0);
		rt=dep[maxSpot]+1;
		if(k==1)cout<<rt/2+1<<endl;
		else{
			int ans1=(rt-1)/2+1;
			int place1=(rt+1)/2;
			int ans2=place1/2;
			cout<<min(ans1,ans2)<<endl;
		}
	}
}
//diff -Z -B
//This is CSP-S. Be serious!

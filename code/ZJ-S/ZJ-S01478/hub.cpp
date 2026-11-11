#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[1000005];
int vis[1000005],n,k,ans=LLONG_MAX,used[1000005],dep[1000005];
void asd(int x){
	used[x]=1;
	for(auto y:g[x]){
		if(!used[y]&&vis[y]) asd(y);
	}
}
void xx(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto y:g[x]){
		if(y!=fa) xx(y,x);
	}
}
void dfs(int x,int xxx){
	if(x==n+1){
		if(xxx!=k) return;
		int cnt=0,maxn=0;
		for(int i=1;i<=n;i++) used[i]=0;
		for(int i=1;i<=n;i++){
			if(!used[i]&&vis[i]) asd(i),cnt++;
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++){
			int minn=LLONG_MAX;
			for(int j=1;j<=n;j++) dep[j]=0;
			dep[0]=-1;
			xx(i,0);
			for(int j=1;j<=n;j++){
				if(vis[j]) minn=min(minn,dep[j]);
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	vis[x]=1;
	dfs(x+1,xxx+1);
	vis[x]=0;
	dfs(x+1,xxx);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1,a,b;i<n;i++){
    		cin>>a>>b;
    		g[a].push_back(b);
    		g[b].push_back(a);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
    return 0;
}
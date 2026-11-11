#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
const int N=1e6+5,M=1e18;
int c,_,n,k,a[N],ans,su;
vector<int> g[N];
void dds(int u,int fa,int dep){
	if(a[u]==1) {
		su=min(su,dep);
	}
	for(int v:g[u]){
		if(v==fa) continue;
		dds(v,u,dep+1);
	}
}
bool bo[N];
void ch(int u,int fa){
	if(a[u]==0) return ;
	bo[u]=1;
	for(int v:g[u]){
		if(v==fa) continue;
		ch(v,u);
	}
}
void dfs(int u,int re){
	if(re==0){
		int che=0;
		for(int i=1;i<=n;i++) bo[i]=0; 
		for(int i=1;i<=n;i++){
			if(a[i]==1&&bo[i]==0){
				ch(i,0);
				che++;
			}
		}
		if(che>2) return ;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				su=M;
				dds(i,0,0);
				sum=max(sum,su);
			} 
		}
		ans=min(ans,sum);
		return ;
	}
	if(u==n+1)
		return ;
	a[u]=1;
	dfs(u+1,re-1);
	a[u]=0;
	dfs(u+1,re);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear(),a[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n){
			cout<<0<<'\n';continue;
		}
		ans=M;
		dfs(1,k);
		cout<<ans<<'\n';
	}
	return 0;
}
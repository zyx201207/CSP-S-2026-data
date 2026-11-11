#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,T;
int n,k;
vector<int> t[N];
int dep[N],fa[N];
int vis[N];
int maxd;
vector<int> mdu;
void build(int root,int fr){
	vis[root]=1;
	dep[root]=dep[fr]+1;
	if(dep[root]>maxd) mdu.clear();
	maxd=max(maxd,dep[root]);
	if(dep[root]==maxd) mdu.push_back(root);
	fa[root]=fr;
	int l=t[root].size();
	for(int i=0;i<l;i++){
		int p=t[root][i];
		if(vis[p]) continue;
		build(p,root);
	}
}
int vist[N];
int dfs(int root){
	vist[root]=1;
	int ans=0;
	int l=t[root].size();
	for(int i=0;i<l;i++){
		int p=t[root][i];
		if(vist[p]) continue;
		ans+=dfs(p);
	}
	vist[root]=0;
	return ans+1;
}
bool check(int x){
	int u;
	memset(vist,0,sizeof(vist));
	int l=mdu.size();
	for(int i=0;i<l;i++){
		u=mdu[i];
		for(int j=1;j<=x;j++){
			vist[u]=1;
			u=fa[u];
		}
	}
	int tmp;
	for(int i=1;i<=n;i++){
		if(vist[i]==0){
			tmp=dfs(i); 
		}
	}
	if(tmp-1<=k) return 1;
	return 0;
}
void solve(){
	for(int i=1;i<=n;i++) t[i].clear();
	memset(dep,0,sizeof(dep));
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	build(1,0);
	int l=0,r=maxd;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	cout<<l<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

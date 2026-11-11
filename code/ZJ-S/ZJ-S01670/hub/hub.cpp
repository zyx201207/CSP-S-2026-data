#include <bits/stdc++.h>
#define syc nb666
#define endl '\n'
#define ll long long
using namespace std;
const int N=1e3+10;
int c,t,n,k,ans=1e9;
int Log[N];
int choose[N],vis[N];
int st[N][25];
int dep[N],fa[N];
vector<int> g[N];
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	st[u][0]=fa;
	for(int i=1; i<=22; i++) {
		st[u][i]=st[st[u][i-1]][i-1];
	}
	for(auto v:g[u]) {
		if(v!=fa) {
			dfs(v,u);
		}
	}
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=22; i>=0; i--) {
		if(dep[st[x][i]]>=dep[y]) x=st[x][i];
	}
	if(x==y) return x;
	for(int i=22; i>=0; i--) {
		if(st[x][i]!=st[y][i]) {
			x=st[x][i],y=st[y][i];
		}
	}
	return st[x][0];
}
void init() {
	ans=1e9;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		init();
		for(int i=1; i<=n; i++) g[i].clear();
		for(int i=1; i<=n-1; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		//	for(int i=1;i<=n;i++) cout<<i<<' '<<st[i][0]<<endl;
		for(int i=0; i<(1<<n); i++) {
			int cnt=0,idx=0,cntt=0;
			int huan=0;
			memset(vis,0,sizeof vis);
			for(int j=1; j<=n; j++) {
				if((i>>(j-1))&1) {
					cnt++;
				}
			}
			if(cnt==k) {
				for(int j=1; j<=n; j++) {
					if((i>>(j-1))&1) {
						//cout<<j<<' ';
						choose[++idx]=j;
						vis[j]=1;
					}
				}
				//	for(int j=1;j<=idx;j++) cout<<choose[j]<<' ';
				//cout<<endl;
				if(vis[1]) huan++;
				for(int j=1; j<=idx; j++) {
					int l=choose[j];
					if(!vis[st[l][0]]) huan++;
				}
				//	cout<<huan<<endl;
				if(huan>2) continue;
				for(int j=1; j<=n; j++) {
					if((i>>(j-1))&1) {
						continue;
					} else {
						int res=1e9;
						for(int v=1; v<=idx; v++) {
							int lc=lca(j,choose[v]);
							res=min(res,dep[j]+dep[choose[v]]-2*dep[lc]);
						}
						cntt=max(cntt,res);
					}
				}
				ans=min(ans,cntt);
				//	cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
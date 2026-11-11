#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c;
namespace Work1_3 {
	const int maxn=15,maxk=4;
	int T,n,k,dep[maxn],f[maxn][5];
	vector<int>e[maxn];
	bool vis[maxn];
	int col[maxn],cntc;
	void dfsc(int u,int fa) {
		//for(auto v:e[u]) {
		int len=e[u].size();
		for(int i=0; i<len; i++) {
			int v=e[u][i];
			if(v==fa||col[v]||!vis[v]) continue;
			col[v]=col[u];
			dfsc(v,u);
		}
	}
	void dfs(int u,int fa) {
		//for(auto v:e[u]) {
		int len=e[u].size();
		for(int i=0; i<len; i++) {
			int v=e[u][i];
			if(v==fa) continue;
			dep[v]=dep[u]+1,f[v][0]=u;
			for(int k=1; k<=maxk; k++) f[v][k]=f[f[v][k-1]][k-1];
			dfs(v,u);
		}
	}
	int lca(int x,int y) {
		if(dep[x]<=dep[y]) swap(x,y);
		for(int k=4; k>=0; k--) if(dep[f[x][k]]>=dep[y]) x=f[x][k];
		if(x==y) return x;
		for(int k=4; k>=0; k--) if(f[x][k]!=f[y][k]) x=f[x][k],y=f[y][k];
		return f[x][0];
	}
	int cntw(int x,int y) {
		return dep[x]+dep[y]-2*dep[lca(x,y)];
	}
	void solve() {
		cin>>T;
		while(T--) {
			for(int i=1; i<=n; i++) e[i].clear();
			cin>>n>>k;
			for(int i=1,u,v; i<n; i++) {
				cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
			}
			dfs(1,0);
			int mask=(1<<n)-1,ans=100;
			for(int S=0; S<=mask; S++) {
				int cnt=0,tmp=S,val=-1;
				for(int i=1; i<=n; i++) {
					if(tmp&1) cnt++,vis[i]=1;
					else vis[i]=0;
					tmp>>=1;
				}
				if(cnt!=k) continue;
				cntc=0;
				for(int i=1; i<=n; i++) col[i]=0;
				for(int i=1; i<=n; i++) {
					if(!vis[i]||col[i]) continue;
					col[i]=++cntc;
					dfsc(i,0);
				}
				if(cntc>2) continue;
				for(int i=1,d; i<=n; i++) {
					d=100;
					for(int j=1; j<=n; j++) {
						if(!vis[j]) continue;
						d=min(d,cntw(i,j));
					}
					val=max(val,d);
				}
				ans=min(ans,val);
			}
			cout<<ans<<"\n";
		}
		exit(0);
	}
}
namespace Work7 {
	const int maxn=1e3+10,maxk=10;
	int T,n,k,dep[maxn],f[maxn][15];
	vector<int>e[maxn];
	bool vis[maxn];
	void dfs(int u,int fa) {
		//for(auto v:e[u]) {
		int len=e[u].size();
		for(int i=0; i<len; i++) {
			int v=e[u][i];
			if(v==fa) continue;
			dep[v]=dep[u]+1,f[v][0]=u;
			for(int k=1; k<=maxk; k++) f[v][k]=f[f[v][k-1]][k-1];
			dfs(v,u);
		}
	}
	int lca(int x,int y) {
		if(dep[x]<=dep[y]) swap(x,y);
		for(int k=4; k>=0; k--) if(dep[f[x][k]]>=dep[y]) x=f[x][k];
		if(x==y) return x;
		for(int k=4; k>=0; k--) if(f[x][k]!=f[y][k]) x=f[x][k],y=f[y][k];
		return f[x][0];
	}
	int cntw(int x,int y) {
		return dep[x]+dep[y]-2*dep[lca(x,y)];
	}
	void solve() {
		cin>>T;
		while(T--) {
			for(int i=1; i<=n; i++) e[i].clear();
			cin>>n>>k;
			for(int i=1,u,v; i<n; i++) {
				cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
			}
			dfs(1,0);
			int ans=1e9;
			for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) {
					int val=-1;
					for(int k=1; k<=n; k++) {
						int d=min(cntw(i,k),cntw(j,k));
						val=max(val,d);
					}
					ans=min(ans,val);
				}
			cout<<ans<<"\n";
		}
		exit(0);
	}
}
namespace Work13_14 {
	int T,n,k;
	void solve() {
		cin>>T;
		while(T--) {
			cin>>n>>k;
			for(int i=1,u,v; i<n; i++) cin>>u>>v;
			int m=n/2;
			int l=1,r=m+1,res=m+1;
			while(l<=r) {
				int mid=(l+r)/2,tmp=mid*2-1;
				if(tmp>=k) r=mid-1,res=mid;
				else l=mid+1;
			}
			if(res*2-2>=k) res--;
			cout<<res<<"\n";
		}
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c;
	if(c<=3) Work1_3::solve();
	if(c==7) Work7::solve();
	if(c==13||c==14) Work13_14::solve();
	return 0;
}

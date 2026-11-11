#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
inline ll readll() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
const int maxn=2e6+10;
int vis[maxn];
ll a[maxn];
vector<int> g[maxn];
int c,T,minstep,sum;
void dfs(int u,int ed,int step) {
	if(step>minstep) return;
	if(u==ed) {
		if(step<minstep) {
			minstep=step;
			sum=1;
			return;
		}
		if(step==minstep) {
			sum++;
			return; 
		}
	}
	for(int v:g[u]) {
		if(v>ed) continue;
		dfs(v,ed,step+1);
	}
}
void solve() {
	int n=read();
	ll d=readll();
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) a[i]=readll();
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(a[j]-a[i]<=d)
				g[i].emplace_back(j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			minstep=j-i,sum=0;
			dfs(i,j,0);
			if(sum==2) ans++;
		}
	}
	printf("%d\n",ans);
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}

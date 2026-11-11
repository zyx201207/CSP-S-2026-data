#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int a[N];
int s[N],t[N];
int dis[N],sub[N],huan[N];
int ans=0;
bool vis[N][N];
bool vs[N][N];
void dfs(int u,int v) {
	if (u==v) return ;
	for (int i=1;i<=m;i++) {
		if (i==u) continue;
		if (vis[i][u]&&!vs[i][u]&&!vs[u][i]) {
			ans+=dis[i];
			if (sub[i]==-1) {
				if (u!=v) ans+=huan[i];
			}
			vs[i][u]=1;
			vs[u][i]=1;
			dfs(i,v);
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		int k; cin>>k;
		int last;
		for (int x=1,y=1;x<=k;x++,y++) {
			cin>>s[x]>>t[y];
			if (sub[s[x]]!=0) sub[s[x]]=-1,huan[s[x]]+=t[y];
			else sub[s[x]]=i,dis[s[x]]=t[y];
			if (x==1) last=s[x];
			else {
				vis[last][s[x]]=1;
				vis[s[x]][last]=1;
				last=s[x];
			}
		}
	}
	while (q--) {
		ans=0;
		int S,T; cin>>S>>T;
		ans+=(a[S]+a[T]);
		if (vis[S][T]) cout<<ans+dis[S]+dis[T]<<'\n';
		else {
			memset(vs,0,sizeof(vs));
			dfs(S,T);
			cout<<ans<<'\n';
		}

	}
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3

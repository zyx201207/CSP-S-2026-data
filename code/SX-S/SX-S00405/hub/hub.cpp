#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);i++)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);i--)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);i++)
typedef long long ll;
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'

template<typename T=int>T read(){T x;cin>>x;return x;}
const int N=2e6+5;
vector<int> e[N];
int p[N],dep[N],fa[N],f[21][N];
bool vis[N];
int C,n,k;
void dfs(int u,int faa){
//	cout<<u<<endl;
	p[u]=faa;
	f[0][u]=faa;
	dep[u]=dep[faa]+1;
	for(auto v:e[u]){
		if(v==faa) continue;
		dfs(v,u);
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	foR(i,20,0) if(dep[f[i][x]]>=dep[y]) x=f[i][x];
	if(x==y) return x;
	foR(i,20,0){
		if(dep[f[i][x]]!=dep[f[i][y]]){
			x=f[i][x],y=f[i][y];
		}
	}
	return f[x][0];
}
void MAIN(){
	cin>>n>>k;
	For(i,1,n) e[i].clear(),dep[i]=p[i]=fa[i]=f[0][i]=0;
	Rep(i,1,n,u,v){
		cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	For(i,1,20)For(j,1,n) f[i][j]=f[i-1][f[i-1][j]];
	int ans=n;
	Rep(S,0,1<<n){
		if(__builtin_popcount(S)!=k) continue;
		vector<int> v;
		fill(vis+1,vis+n+1,0);
		For(i,1,n) fa[i]=i;
		For(i,1,n){
			if(S>>(i-1)&1) v.pb(i),vis[i]=1;
		}
		for(auto x:v){
			if(vis[p[x]]){
				int pp=find(x),q=find(p[x]);
				if(pp==q) continue;
				fa[pp]=q;
			}
		}
		int cnt=0;
		for(auto x:v){
			if(fa[x]==x){
				cnt++;
			}
		}
		if(cnt>2) continue;
		int res=0;
		For(i,1,n){
			if(vis[i]) continue;
			int d=n;
			for(auto x:v){
				int LCA=lca(i,x);
//				cout<<i<<" "<<x<<" "<<LCA<<endl;
				d=min(d,dep[i]+dep[x]-2*dep[LCA]);
			}
			res=max(res,d);
		}
		ans=min(res,ans);
	}
	cout<<ans<<endl;
}signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	C=read();int t=read();while(t--){
		MAIN();
	}
	return 0;
}
/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
/*0 1
5 2
1 2
2 3
3 4
4 5*/

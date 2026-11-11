#include<bits/stdc++.h>
#define int long long
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define dFor(i,j,k) for(int i=(j);i>=(k);--i)
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define umap unordered_map
#define lwb lower_bound
#define upb upper_bound
#define all(ve) ve.begin(),ve.end()
#define All(arr,lst) arr+1,arr+(lst)+1
using namespace std;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef pair<int,int> pii;
typedef set<int>::iterator iter;
const int _=1000005,mod=1e9+7,inf=1e18,base=20280031;
mt19937_64 rnd(random_device{}());
template<class T>inline void cmax(T &x,const T &y){if(y>x) x=y;}
template<class T>inline void cmin(T &x,const T &y){if(y<x) x=y;}
inline void madd(int &x,const int &y){x=(x+y)%mod;}
inline void mmul(int &x,const int &y){x=(x*y)%mod;}
namespace DEBUG{
	template<class T>inline void _debug(const char *s,T x){cerr<<s<<'='<<x<<endl;}
	template<class T,class...Nxt>void _debug(const char *s,T x,Nxt...nxt){
		int d=0; while(*s!=','||d) d+=*s=='(',d-=*s==')',cerr<<*s++;
		cerr<<'='<<x<<',',_debug(s+1,nxt...);
	}
	#define debug(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}
bool M_st; using namespace DEBUG;
int n,K,d[_],dep[_],fa[_][21]; vector<int>e[_];
namespace bl{
	int ans,a[_]; bitset<_>vis; queue<int>q;
	void dfs(int u){for(int v:e[u]) if(v^*fa[u]) *fa[v]=u,dep[v]=dep[u]+1,dfs(v);}
	inline int LCA(int l,int r){ if(dep[l]>dep[r]) swap(l,r);
		dFor(i,20,0) if((1<<i)<=dep[r]-dep[l]) r=fa[r][i]; if(l==r) return l;
		dFor(i,20,0) if(fa[l][i]^fa[r][i]) l=fa[l][i],r=fa[r][i]; return *fa[l];
	}
	inline int dis(int x,int y){int lca=LCA(x,y); return dep[x]+dep[y]-(dep[lca]<<1);}
	inline void bfs(int S){vis[S]=true,q.push(S); while(!q.empty()){int u=q.front(); q.pop(); for(int v:e[u]) if(!vis[v]) vis[v]=true,q.push(v);}}
	inline void to_do(){
		For(i,1,n) vis[i]=false; int cnt=0; For(i,1,K) if(!vis[a[i]]){if(++cnt>2) return ; bfs(a[i]);}
		int res=0; For(i,1,n){int D=inf; For(j,1,K) cmin(D,dis(i,a[j])); cmax(res,D);} cmin(ans,res);
	}
	void dg(int d){if(d==K+1) return to_do(),void(); for(a[d]=a[d-1]+1;a[d]<=n-K+d;++a[d]) dg(d+1);}
	inline int solve(){
		cin>>n>>K; For(i,1,n) vector<int>().swap(e[i]); For(i,2,n){int u,v; cin>>u>>v,e[u].eb(v),e[v].eb(u);} 
		dep[1]=*fa[1]=0,dfs(1); For(j,1,20) For(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
		ans=inf,dg(1); return ans;
	}
}
namespace A{
	int m,op;
	inline int solve(){
		cin>>n>>K,m=n-1>>1,op=K&1; For(i,2,n){int u,v; cin>>u>>v;} 
		if(K>=n) return 0; if(K>=m) return 1; return m-K+4+3>>2;
	}
	 
}
bool M_ed; signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); FIO("hub");
	int sib,T; cin>>sib>>T;
	if(13<=sib<=14) while(T--) cout<<A::solve()<<'\n';
	else if(0<=sib<=20) while(T--) cout<<bl::solve()<<'\n';
	return 0; //return printf("memory used: %.3lfMB\n",fabs(&M_ed-&M_st)/1048576.0),0;
}
/*
0 2
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

1
2
*/

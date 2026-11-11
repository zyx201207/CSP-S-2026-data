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
const int _=505,__=500005,mod=1e9+7,inf=1e18,base=20280031;
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
int sib,n,m,D,Q,K[_],d[_][_],dis[__],w[__]; bitset<_>vis; vector<int>a[_],t[_]; vector<pii>e[__]; priority_queue<pii,vector<pii>,greater<pii>>q;
inline void Dijkstra(int S){
	For(i,1,n) d[S][i]=inf,vis[i]=false; For(i,1,m) dis[i]=inf; q.push(mk(d[S][S]=0,S));
	while(!q.empty()){
		int u=q.top().se; q.pop(); if(vis[u]) continue; vis[u]=true;
		For(j,1,K[u]){
			int p=a[u][j]; if(d[S][u]+t[u][j]>=dis[p]) continue; dis[p]=d[S][u]+t[u][j];
			for(auto&[v,st]:e[p]){int w=t[u][j]+t[v][st]; if(d[S][u]+w<d[S][v]) q.push(mk(d[S][v]=d[S][u]+w,v));}
		}
	}
}
bool M_ed; signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); FIO("subway");
	cin>>sib>>n>>m>>D>>Q; For(i,1,m) cin>>w[i];
	For(i,1,n){cin>>K[i],a[i].resize(K[i]+1),t[i].resize(K[i]+1); For(j,1,K[i]) cin>>a[i][j]>>t[i][j],e[a[i][j]].eb(i,j);} For(S,1,n) Dijkstra(S);
	while(Q--){int x,y,res=inf; cin>>x>>y; for(auto&[i,st1]:e[x]) for(auto&[j,st2]:e[y]) cmin(res,t[i][st1]+d[i][j]+t[j][st2]); cout<<w[x]+res+w[y]<<'\n';}
	return 0; //return printf("memory used: %.3lfMB\n",fabs(&M_ed-&M_st)/1048576.0),0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/

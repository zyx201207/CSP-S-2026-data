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
const int _=2000005,mod=1e9+7,inf=1e18,base=20280031;
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
int sib,T,n,D,x[_],L[_],R[_];
namespace n3{
	const int __=305; int d[__][__],f[__][__];
	inline int solve(){
		cin>>n>>D; For(i,1,n) cin>>x[i];
		For(i,1,n) L[i]=lwb(All(x,n),x[i]-D)-x,R[i]=upb(All(x,n),x[i]+D)-x-1;
		For(i,1,n){For(j,1,n) f[i][j]=j<=R[i],d[i][j]=j<=i?0:inf; For(j,i+1,n){if(d[i][L[j]]==inf) break; d[i][j]=d[i][L[j]]+1;}}
		For(len,1,n) for(int i=1,j=len;j<=n;++i,++j) if(d[i][j]^inf&&!f[i][j]) For(k,i+1,R[i]) if(1+d[k][j]==d[i][j]&&(f[i][j]+=f[k][j])>2){f[i][j]=3; break;};
		int ans=0; For(i,1,n) For(j,i,n) ans+=f[i][j]==2; return ans;
	}
}
bool M_ed; signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); FIO("migrate");
	cin>>sib>>T; 
	if(0<=sib<=25) while(T--) cout<<n3::solve()<<'\n';
	return 0; 	//return printf("memory used: %.3lfMB\n",fabs(&M_ed-&M_st)/1048576.0),0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
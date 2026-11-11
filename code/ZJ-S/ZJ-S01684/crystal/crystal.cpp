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
const int _=500005,mod=1e9+7,inf=1e18,base=20280031;
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
int n,m,ans=0,a[_],s[_];
bool M_ed; signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); FIO("crystal");
	cin>>n>>m; For(i,1,n) cin>>a[i]; sort(All(a,n)); For(i,1,n) s[i]=s[i-1]+a[i];
	For(i,1,n){int l=1,r=i,mid,j=i; while(l<=r) (mid=l+r>>1,a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)?(j=mid,r=mid-1):l=mid+1; cmax(ans,i-j+1);}
	cout<<ans;
	return 0; //return printf("memory used: %.3lfMB\n",fabs(&M_ed-&M_st)/1048576.0),0;
}
/*
5 5
1 2 4 8 9

3
*/
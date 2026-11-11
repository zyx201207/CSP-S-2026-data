#include <bits/stdc++.h>
using namespace std;
namespace MySpace{
	#define lowbit(x) ((x)&(-(x)))
	inline void read(){}
	template<typename T,typename... R>
	inline void read(T& x,R&... oth){
		x=0;T f=1;
		char c=getchar();
		while (c<'0' || c>'9'){
			if (c=='-') f=-1;
			c=getchar();
		}
		while (c>='0' && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
		x=x*f;
		read(oth...);
		return;
	}
	template<typename T>
	T qpow(T a,T n,T p){
		T res=1;
		for (;n;n>>=1){
			if (n&1) res=(long long)(res*a)%p;
			a=(long long)(a*a)%p;
		}
		return res;
	}
	template<typename T>
	T gcd(T a,T b){return b<=0?a:gcd(b,a%b);}
}
using namespace MySpace;
//const int LuoTianYi=0x66ccff;
/*
15:27 
注意到我们对一个点u建出最短路树之后
对于一个对(u,v)满足dep_u=dep_v+1或者
不对不对，完全不对
怎么放两道不可做题，吓死了 
*/ 
#define int long long
const int maxn=2e6+5;
int C,T;
int n,d;
int a[maxn];
vector<int> e[maxn];
bitset<maxn> vis;
int dis[maxn]; 
int ans;
int cnt[maxn];
void dfs(int u,int d=0){
	//printf("--%lld %lld--\n",u,d);
	if (dis[u]>d) dis[u]=d,cnt[u]=1;
	else if (dis[u]==d) cnt[u]++;
	for (auto v:e[u]){
		if (vis[v]) continue;
		vis[v]=1;
		dfs(v,d+1);
		vis[v]=0;
	}
	return;
}
int aaa(int x){
	return x<0?-x:x;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(C,T);
	while (T--){
		read(n,d);
		for (int i=1;i<=n;i++) read(a[i]),e[i].clear();
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (aaa(a[i]-a[j])<=d){
					e[i].push_back(j);
					e[j].push_back(i);
					//printf("--%lld %lld %lld--\n",aaa(a[i]-a[j]),i,j);
				}
			}
		}
		ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) dis[j]=1e9,cnt[j]=0;
			dis[i]=0;vis=0;
			vis[i]=1;
			dfs(i);
			for (int i=1;i<=n;i++) if (cnt[i]==2) ans++;
		}
		printf("%lld\n",(long long)(ans/2));
	}



	return 0;
}


/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/





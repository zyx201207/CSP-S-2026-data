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
15:58 
我为什么会T4了？
注意到跟随连通块数量为凸函数，可以wqs
然后我们发现在不限制联通块的情况下，答案二分可以轻松得到选k个的答案
复杂度两个log 
注意特判答案是1或0的情况 

16:26 我先换换脑子写写暴力 
*/
#define int long long
const int maxn=1e6+5;
int T;
int n,k;
vector<int> e[maxn];
int f[maxn][4][4];
int cnt[maxn][4][4];
int getm(int u=1){
	int ans=1e18;
	for (int i=0;i<=2;i++) ans=min({ans,f[u][i][0],f[u][i][1]});
	return ans;
}
int getc(int u=1){
	int ans=1e18,p=0;
	for (int i=0;i<=2;i++){
		for (int j=0;j<=1;j++){
			if (f[u][i][j]<ans){
				ans=f[u][i][j];
				p=cnt[u][i][j];
			}
		}
	}
	return p;
}
void dfs(int u,int f=0){
	vector<int> tmp[4];
	for (auto v:e[u]){
		if (v==f) continue;
		dfs(v,u);
		for (int i=0;i<=2;i++){
			tmp[i].push_back(getm(v)); 
			cnt[u][i][0]+=getc(v);
		}
	}
	for (int i=0;i<=2;i++){
		tmp[i].push_back(0);tmp[i].push_back(0);
		sort(tmp[i].begin(),tmp[i].end(),greater<int>());
		f[u][i][0]=(tmp[i][0]+tmp[i][1]+2);
	}
	tmp[0].clear();tmp[1].clear();tmp[2].clear();
	for (int i=2;~i;i--){
		int maxx=0,maxp=0;
		for (auto v:e[u]){
			if (v==f) continue;
			if (f[v][i][1]>maxx){
				maxp=v;
				maxx=f[v][i][1];
			}
		}
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(T,T);
	while (T--){
		read(n,k);
		for (int i=1;i<n;i++){
			int u,v;read(u,v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (n==k){
			printf("0\n");
			continue;
		}
		if (n==k+1){
			printf("1\n");
			continue;
		}
		int l=-2e6,r=2e6;
		while (l<r){
			int c=(l+r)>>1;
			for (int i=1;i<=n;i++) memset(f[i],0,sizeof f[i]);
			dfs(1);
			if (getc()<k) l=mid+1;
			else r=mid;
		}
		c=l;dfs(1);
		printf("%lld\n",getm()-getc()*c);
	}


	return 0;
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

*/





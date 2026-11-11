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
#define int long long
const int maxn=5e5+5;
int n,m;
int a[maxn];
int ans;
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n,m);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	int d=0;
	for (int i=1;i<=n;i++){
		for (;!q.empty() && q.size()*a[i]-d>m;d-=q.front(),q.pop());
		ans=max(ans,(int)q.size()+1);
		q.push(a[i]);d+=a[i];
	}
	printf("%lld",ans);


	return 0;
}








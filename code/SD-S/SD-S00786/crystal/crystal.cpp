#include <bits/stdc++.h>
#include <assert.h>
#include <limits.h>
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pct(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define lowbit(x) ((x)&-(x))
#define dbg(x)
using namespace std;
constexpr int N=500010,base=389,mod=998244353;

template<class T> inline void ckmin(T &x,T y){x=(x<y)?x:y;}
template<class T> inline void ckmax(T &x,T y){x=(x>y)?x:y;}

namespace Zhchz{
	int n;
	ll m,a[N],sum[N];
	
	signed main(){
		ios::sync_with_stdio(0);cin.tie(0);
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		ll ans=1,l=0;
		for(int i=1;i<=n;i++){
			while(sum[i]-sum[l]+m < a[i]*(i-l) && l<i) ++l;
			ckmax(ans,i-l);
		}
		cout<<ans;
		return 0;
	}
}signed main(){return Zhchz::main();}

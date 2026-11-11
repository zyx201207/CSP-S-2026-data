#include<cstdio>
#include<algorithm>
#include<queue>
typedef long long ll;
const ll N=2e6+5;
std::priority_queue<ll > hp;
ll n,m;
ll a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(ll i=1;i<=n;++i){
		scanf("%lld", &a[i]);
	}std::sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		m-=(a[i]-a[i-1])*hp.size();
		hp.push(-a[i]);
		while(m<0){
			ll t=hp.top();
			hp.pop();
			m+=a[i]+t;
		}ans=std::max(ans,(ll )hp.size()); 
	}printf("%lld\n", ans);
	return 0;
}
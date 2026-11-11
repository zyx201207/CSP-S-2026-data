#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],ans,pre[N];
ll check(ll x) { //以a[x]为基准，最多用多少颗能量水晶合成一颗大水晶 
	ll ret=0;ll tmp=x*a[x]-pre[x-1];
	for (ll i=1;i<=x;i++) {
		if (pre[i-1]-i*a[x] <= m-tmp) {
			ret=x-i+1;
			break;
		}
	}
	return ret;
}
void solve1() { //测试点1~9 
	sort(a+1,a+n+1);
	pre[0]=0;for (ll i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for (ll i=1;i<=n;i++) {
		//以a[i]为基准值
		ll c=check(i);
		ans=max(ans,c); 
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (ll i=1;i<=n;i++) cin>>a[i];
	if (n<=5000&&m<=1000000000)solve1();
	else {
		sort(a+1,a+n+1);
		for (ll i=1;i<=n;i++ ) pre[i]=pre[i-1]+a[i];
		ll l=1;
		for (ll r=1;r<=n;r++) { //枚举基准a[r] 
			while (r*a[r]-l*a[r]-pre[r-1]+pre[l-1]>m) l++; 
			ans=max(ans,r-l+1);
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
ll c,n,m,d,q;
ll z[N];
struct Node{
	ll k,a[N],t[N];
}s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i <= m;i ++) cin >> z[i];
	for(ll i = 1;i <= n;i ++){
		cin >> s[i].k;
		for(ll j = 1;j <= s[i].k;j ++) cin >> s[i].a[j] >> s[i].t[j];
	}
	while(q --){
		ll x,y,ans = INT_MAX;
		cin >> x >> y;
		ll cnt = z[x] + z[y];
		ans = min(ans,cnt);
		cout << ans << endl;
	}
	return 0;
}

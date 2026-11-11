#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;

using LL = long long;

void _main();

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin>>c>>t;
	while(t --) _main();
	return 0;
}

int n;
LL d, a[2000010];
int pre[2000010], nxt[2000010];

void _main(){
	cin>>n>>d; LL ans = 0;
	for(int i = 1; i <= n; i ++) cin>>a[i], pre[i] = nxt[i] = 0;
	if(n == 1 || n == 2) return cout<<"0\n", void();
	a[n + 1] = 3e18 + 114514, a[0] = -3e18 - 114514;
	for(int i = 1; i <= n - 3; i ++){
		if(a[i + 3] - a[i] > d && a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d) {
			pre[i + 3] = i + 1;
			nxt[i] = i + 2;
		}
	}
	for(int i = 1; i <= n; i ++){
		if(a[i] - a[i - 1] > d) pre[i] = i;
		pre[i] = (pre[i] ? pre[i] : pre[i - 1]);
	}
	for(int i = n; i; i --){
		if(a[i + 1] - a[i] > d) nxt[i] = i;
		nxt[i] = (nxt[i] ? nxt[i] : nxt[i + 1]);
	}
	for(int i = 2; i <= n - 2; i ++){
		if(a[i + 3] - a[i] > d && a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d) {
			ans += 1ll * max(0, i - pre[i + 2] + 1) * max(0, nxt[i + 1] - (i + 3) + 1);
		}
	}
	cout<<ans<<'\n';
}

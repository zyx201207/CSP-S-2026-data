#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=5e6+9;
int n;
ll m;
ll a[maxn], b[maxn];
ll pre[maxn]; int frst[maxn];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	int blen=unique(b+1, b+1+n)-b-1;
	for (int i=1; i<=n; i++) { // calc prefixs
		pre[i]=pre[i-1]+a[i];
	}
	for (int i=1;i<=blen;i++) {
		ll u=b[i];
		frst[i] = upper_bound(a+1,a+1+n,u)-a-1;
//		if (a[frst[i]]!=b[i]) cout << "!!!" << '\n';
	}
	int ans = 0;
	ll maxx=0;
	for (int i=1; i<=blen; i++) {
		ll crr=b[i]; int j=frst[i];
		for (int k=1;k<=j;k++) {
			if (j-k+1<=ans) break;
			ll delta = pre[j]-pre[k-1];
			if (crr*(j-k+1)-delta<=m) {
				ans = max(ans, j-k+1);
				break;
			}
		}
	}
	cout << ans;

	return 0;
}































#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5;
ll n, m;
ll a[N], cnt = -1, p[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 5000)sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++)a[i] = a[n] - a[i];
	for (ll i = 1; i <= n; i++)p[i] = p[i - 1] + a[i];
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//	cout<<endl;
	for (ll i = 1; i <= n; i++) {
		for (ll j = n; j >= i ; j--) {
			ll v = p[j - 1] - p[i - 1] - (j - i) * a[j];
			if (v <= m) {
				cnt = max(j - i + 1, cnt);
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
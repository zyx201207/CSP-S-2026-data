#include <bits/stdc++.h>
using namespace std;
int T = 1;
#define ll long long
#define endl '\n'
#define vi vecotr<ll>
#define pii pair<ll,ll>
#define dl double
ll n, m, a[200005], f[200005];

//string
//dl
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	f[1] = 0;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + (a[i] - a[i - 1]) * (i - 1);
		if (f[i] > m) {
			cout << i - 1 << endl;
			return;
		}
	}
	return;
}

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cin<<T;
	while (T--) {
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define endl '\n'
const int MAXN = 5e5+5;
int n, a[MAXN];
ll m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int T = a[2] - a[1], sum = 0, ans = 1;
	for (int i = 1; sum + T * i <= m; i++) {
		sum += T * i;
		ans++;
		if (ans == n)
			break;
	}
	cout << ans;

	return 0;
}

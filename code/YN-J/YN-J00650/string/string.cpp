#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n;
ll p[N], q[N];
char m[N];
string s1, s2;
ll num = 0, ans = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> m[i];
		q[i] = p[i];
		num += p[i];
	}
	for (int i = 1, j = n; i <= n, j >= 1;) {
		if (p[i] >= q[j]) {
			if (m[i] != m[j])
				ans += q[j];
			p[i] -= q[j--];
		} else {
			if (m[i] != m[j])
				ans += p[i];
			q[j] -= p[i++];
		}
	}
	cout << ans / 2;
	fclose(stdin);
	fclose(stdout);
}
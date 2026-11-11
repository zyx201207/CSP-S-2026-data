#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 214514;
ll n, s, ans;
ll b[N];
string s1;

struct node {
	ll sum;
	string c;
} a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sum >> a[i].c;
		s += a[i].sum;
	}
	if (n == 1) {
		cout << ans;
		return 0;
	}
	s1 += " ";
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].sum; j++)
			s1 += a[i].c;
	}
	cout << s1 << endl;
	for (int i = 1; i <= (s + 1) / 2; i++) {
		if (s1[i] != s1[n + 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
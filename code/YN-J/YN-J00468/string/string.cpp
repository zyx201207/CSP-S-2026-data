#include <bits/stdc++.h>
#include <cstdio>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
int n;

struct node {
	int num;
	char c;
} a[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	OI
	string s;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].num >> a[i].c;
		sum += a[i].num;
	}
	ll ans = 0;
	ll temp = 0;
	char tempc = a[1].c;
	ll cnt1 = 0;
	for (int i  = 1; i <= n; ++i) {
		cnt1 += max(a[i].num, a[n - i + 1].num);
		if (a[i].c != a[n - i + 1].c) {
			ans += a[i].num;
			if ((tempc != a[i].c && temp >= 0) || temp < 0) {
				ans += temp;
			}
			temp = a[n - i + 1].num - a[i].num;
			tempc = a[i].c;
//			cout << 1 << ans << "\n";
		} else {
			if (temp < 0)
				ans += a[n - i + 1].num + temp;
			else if (tempc != a[i].c)
				ans = ans - temp;
			temp += min(temp + a[n - i + 1].num - a[i].num, 1ll * 0);
//			cout << 2 << ans << "\n";
		}
		if (cnt1 >= sum / 2) {
			break;
		}
	}
	cout << ans;


	return 0;
}
/*
3
2 a
2 b
1 c

3
1 b
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
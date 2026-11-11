#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
struct stu {
	char c;
	int m;
}a[N];
int n;
int sum;
int ans;
string s;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].m >> a[i].c;
		for (int j = 1; j <= a[i].m; j++) {
			s += a[i].c;
		}
		sum += a[i].m;
	}
	string s1,s2;
	/*
	for (int i = 0; i < sum; i++) {
		s1 += s[i];
	}
	for (int i = sum; i < n; i++) {
		s2 += s[i];
	}
	*/
	int x = 0;
	for (int i = (sum / 2) - 1; i >= 0; i--) {
		if (s[i] == s[s.size() - i - 1]) {
			continue;
		}
		else {
			x = i;
			break;
		}
	}
	//	cout << x << '\n';
	for (int i = x; i >= 0; i--) {
		if (s[i] == s[s.size() - i - 1]) {
			continue;
		}
		else {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
4
2 b
1 a
2 b
1 a
*/



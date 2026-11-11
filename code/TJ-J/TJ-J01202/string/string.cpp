#include <iostream>
#include <string>

using namespace std;

#define N 200005

long long cnt, ans = 999999999999999;
int n, a;
char c;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> c;
		while (a--) {
			s.push_back(c);
		}
	}
	int lhalf = s.size() / 2 - 1, rhalf = s.size() - 1 - lhalf;
	int l = 0, r = s.size() - 1;
	while(l <= lhalf && r >= rhalf) {
		if (s[l] != s[r]) {
			cnt++;
		}
		l++;
		r--;
	}
	if (cnt < ans) ans = cnt;
	cout << ans;
	return 0;
}


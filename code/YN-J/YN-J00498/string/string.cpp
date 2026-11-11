#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
string d, num;
int cnt;

bool cmp(char x, char y) {
	return x > y;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int len = d.size();
	cin >> d;
	for (int i = 0; i < len; ++i) {
		if (d[i] >= '0' and d[i] <= '9') {
			num += d[i];
		}
	}
	sort(num.begin(), num.end(), cmp);
	cout << num;
	return 0;
}
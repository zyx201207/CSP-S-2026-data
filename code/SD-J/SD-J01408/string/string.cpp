#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
pair<int, char> s[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	pair<int, char> head = {0, 0}, end = {0, 0};
	for(int i = 1; i <= n; i++) {
		cin >> s[i].first >> s[i].second;
	}
	int l = 1, r = n;
	int sum = 0;
	while(l <= r) {
		if(head.first == 0) {
			head = s[l++];
		} else {
			end = s[r--];
		}
		int m = min(head.first, end.first);
		head.first -= m, end.first -= m;
		if(head.second != end.second) sum += m;
	}
	cout << sum;
	return 0;
}

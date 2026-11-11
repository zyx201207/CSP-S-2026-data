#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n;
pair<int, char> a[N], b[N];
string s;
int l = 1, r = 1;
int sum = 0;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
		b[i].first = a[i].first;
		b[i].second = a[i].second;
		sum += a[i].first;
	}
	int ans = 0;
	reverse(a + 1, a + n + 1);
	int cnt = 0;
	while(l <= n && r <= n) {
		pair<int, char> p1 = a[l], p2 = b[r];
		if(p1.second != p2.second) {
			cnt += min(p1.first, p2.first);
		}
		if(p2.first < p1.first) {
			a[l].first -= p2.first;
			r++;
		} else if(p2.first > p1.first) {
			b[r].first -= p1.first;
			l++;
		} else {
			l++, r++;
		}
	}
	cout << cnt / 2;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
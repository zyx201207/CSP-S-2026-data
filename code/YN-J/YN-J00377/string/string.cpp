#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, sum, summ;
string s;
map<int, int>mpp;
map<char, int>mp, vis, viss, Cnt;

struct node {
	int cnt;
	char c;
	friend bool operator<(node a, node b) {
		if (a.cnt == b.cnt)return a.c < b.c;
		return a.cnt < b.cnt;
	}
} a[N];

int check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i])cnt++;
	}
	return cnt;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].cnt >> a[i].c;
		sum += a[i].cnt;
		sum %= 2, summ += a[i].cnt;
		mp[a[i].c] += a[i].cnt, mpp[i] = abs(1 - a[i].cnt);
		if (viss[a[i].c] == 0)s += a[i].c, viss[a[i].c] = 1;
	}
	if (summ <= N) {
		s = "";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i].cnt; j++)s += a[i].c;
		}
		cout << check(s);
		return 0;
	}
	if (sum == 0) {
		sort(a + 1, a + n + 1);
		int now = 0;
		for (auto c : mp) {
			now += c.second;
		}
		cout << now - mp[a[n].c];
	} else {
		int now = 0;
		for (auto c : mpp) {
			now += c.second;
		}
		cout << check(s)*now << "\n";
	}
	return 0;
}
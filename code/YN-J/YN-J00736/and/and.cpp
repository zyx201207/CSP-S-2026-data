#include <bits/stdc++.h>
using namespace std;
int a[100005];

string sze(int n) {
	string s;
	s = (char)(n % 2 + 96)  + s;
	n /= 2;
	return s;
}

int ezs(string s) {
	int sum;
	reverse(s.begin(), s.end());
	for (int i = 0; i <= s.size() - 1; i++) {
		sum = (s[i] + '0') * pow(2, i);
	}
	return sum;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a + 1, a + 1 + n);
	cout << a[n - 1] ;
	return 0;
}


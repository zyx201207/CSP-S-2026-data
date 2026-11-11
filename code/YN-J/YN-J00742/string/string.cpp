#include <bits/stdc++.h>
using namespace std;
int n, x;
long long sum;
string s, a;
char s1[100000005], s2[1000000005];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.ans", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> x >> a;
		for (int i = 1; i <= x; i++) {
			s += a;
		}
		x = 0;
	}
	int r, l;
	r = s.size() / 2;
	for (long long i = 0; i <= r; i++) {
		s1[i] = s[i];
	}
	for (long long i = s.size(); i > r; i--) {
		s2[i] = s[i];
	}
	for (long long i = 0; i <= r; i++) {
		for (long long j = s.size(); j > r; j--) {
			if (s1[i] != s2[j]) {
				s2[j] = s1[i];
				sum++;
				continue;
			} else {
				continue;
			}

		}
	}
	cout << sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
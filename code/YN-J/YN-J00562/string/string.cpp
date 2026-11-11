#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n;
long long a[10000001];
char s[10000001] ;
long long ans, sum ;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;



	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> s[i];
		sum += a[i];

		while (a[i]--) {
			s1 += s[i];
		}
	}

	long long cnt = sum;
	sum -= 1;

	while (sum--) {
		s2 += s1[sum];
	}

	for (int i = 0; i < cnt; i++) {

		if (s1[i] != s2[i])
			ans++;
	}

	cout << ans / 2;
	return 0;
}
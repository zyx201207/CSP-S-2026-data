#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {

		long long x;
		string a;
		cin >> x >> a;
        for (long long j = 1; j <= x; j++) {
			
			s += a;
		}
	}

	long long sum = s.size();
	long long cnt = 0;
	for (long long i = 0; i < s.size() / 2; i++) {

		if (s[i] != s[sum - i - 1]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long sum = 0;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string s;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		char c;
		cin >> c;
		for (int j = 0; j < a; j++) {
			s[cnt] = c;
			cnt++;
		}
	}
	if (s.size() % 2 == 1) {
		long long g = s.size() / 2;
		for (int i = 1; i <= g; i++) {
			if (s[g + i] != s[g - i]) {
				sum += 1;
			}
		}
	} else {
		long long x = s.size() / 2;
		long long y = x - 1;
		for (int i = 1; i <= x; i++) {
			if (s[x] != s[y]) {
				sum += 1;
			}
			x++;
			y--;
		}
	}
	cout << sum;
	/*string s1;
	for (int i = 0; i < s.size(); i++) {
		s1[i] = s[s.size() - 1 - i];
		if (s1[i] != s[s.size() - 1 - i]) {
			sum++;
		}
	}
	cout << sum / 2;
	*/
	return 0;
}
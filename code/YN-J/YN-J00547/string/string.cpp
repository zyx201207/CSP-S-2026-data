#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	string s = "";
	cin >> n;
	long long a;
	char b;
	long long cnt = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;

		for (int j = 1; j <= a; j++) {

			s += b;
		}
	}

	int len = s.size();
	string s1;

	for (int i = len; i >= 1; i++) {

		s1 = s;

		if (s1 == s) {
			cout << 0 ;
			break;
		}
	}


	return 0;
}
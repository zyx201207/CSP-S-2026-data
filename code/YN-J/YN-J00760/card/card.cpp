#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], t[300005];

void fun(long long js) {
	string s;

	for (int i = js; i <= n; i++) {

		char c = char('0' + a[i]);
		s = s + c;
		int k = s.find(c);

		if (k != s.size() - 1) {
			s.erase(k);
			s = s + c;
		}


	}

	for (int i = 0; i < s.size(); i++) {



		int f = s[i] - '0';

		t[f] += 1;

	}



}

int main() {
	cin >> n >> m;


	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		fun(i);
	}

	for (int i = 1; i <= m; i++) {

		cout << t[i] << " ";
	}

	return 0;
}






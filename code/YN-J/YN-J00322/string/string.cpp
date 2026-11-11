#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) {
		int a;
		string c;
		cin >> a >> c;
		cout << 0;
	}
	if (n == 2) {
		int a1, a2;
		string c1, c2;
		cin >> a1 >> c1;
		cin >> a2 >> c2;
		cout << a1;
		}
		s = s2;
	}
	if(s.size()==1){
		cout<<0
		}else{
			cout<<x[l]
		}
	} else {
		int x[2002];
		string s2, s;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> s2;
			if (s == s2) {
				x[i] += x[i - 1];
				x[i - 1] = 0;
			}
			s = s2;
		}
	sort(x + 1, x + n + 1);
	cout << x[n - 2];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	cout<<"      ";
	string s;
	for (int i = 1; i <= n; i++) {
		
		long long a;
		char c;
		cin >> a >> c;
		s.insert(s.size(), a, c);
//		for (int j = 1; j <= a; j++)
//			s += c;
	}
//	cout<<n;
	
	//cout << s;
	
	long long ans = 0;
	int si = s.size() / 2;

	for (int i = 0; i <= si; i++) {

		if (s[i] != s[s.size() - 1 - i])
			ans++;
	}

	cout << ans << endl;
	return 0;
}

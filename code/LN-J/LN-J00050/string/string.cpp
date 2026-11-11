#include <bits/stdc++.h>
using namespace std;

int n;
string s = "";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; scanf("%d", &n);
	string s = "";
	int x; char c;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		cin >> c;
		for (int i = 1; i <= x; i++)
			s += c;
	}
	//cout << s << "\n";
	int mid;
	if (s.size() & 1)
		mid = (1 + s.size()) / 2;
	else
		mid = s.size() / 2;
	string t1, t2;
	if (s.size() & 1) {
		for (int i = 0; i < mid - 1; i++)
			t1 += s[i];
		for (int i = s.size(); i >= mid; i--)
			t2 += s[i];	
	}
	else {
		for (int i = 0; i < mid; i++)
			t1 += s[i];
		for (int i = s.size(); i >= mid; i--)
			t2 += s[i];
	}
	long long ans = 0;
	//cout << t1 << " " << t2;
	reverse(t2.begin(), t2.end());
	for (int i = 0; i < t1.size(); i++)
		if (t1[i] != t2[i])
			ans++;
	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "", s1, ns1 = "", ns3 = "";
	int n, cnt, sum = 0, bt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cnt >> s1;
		for (int j = 1; j <= cnt; j++) {
			s += s1;
		}
	}//yes
	sum = (s.size() + 1) / 2;
	for (int i = 0; i < sum - 1; i++) {
		ns1 += s[i];
	}
	for (int i = sum; i <= s.size() - 1; i++) {
		ns3 += s[i];
	}
	for (int i = 0; i <= sum - 1; i++) {
		if (ns1 != ns3) {
			bt++;
		}
	}
	if (bt > 0)
		cout << bt - 1;
	else
		cout << 0;
	return 0;
}
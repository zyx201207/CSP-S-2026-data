#include <bits/stdc++.h>
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define int long long
#define endl '\n'
using namespace std;

signed main() {
	File("travel");
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) cout << "1";
	else { cout << "0000"; return 0; }
	
	if (s1[1] == s2[1]) cout << "1";
	else { cout << "000"; return 0; }
	
	bool flag1 = 0, flag2 = 0;
	if (s1[2] >= 'A' && s1[2] <= 'C') flag1 = 0;
	else flag1 = 1;
	if (s2[2] >= 'A' && s2[2] <= 'C') flag2 = 0;
	else flag2 = 1;
	if (flag1 == flag2) cout << "1";
	else { cout << "00"; return 0; }
	
	int d = abs(s1[2] - s2[2]);
	if (d == 1) cout << "1";
	else cout << "0";
	return 0;
}
// 02 01C 02 01D
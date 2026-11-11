#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string c_1, s_1, c_2, s_2;
bool f_1, f_2, f_3, f_4; 
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if (c_1 == c_2) f_1 = 1;
	int flag = 0;
	for (int i = 0; i < s_1.size() - 1; i ++) {
		if (s_1[i] != s_2[i]) flag = 1;
	}
	if (!flag && f_1) f_2 = 1;
	char a = s_1[s_1.size() - 1];
	char b = s_2[s_2.size() - 1];
	if (int(a) > int(b)) swap(a, b);
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'A' && b == 'C') || (a == 'D' && b == 'F')) f_3 = 1;
	if (!f_1 || !f_2) f_3 = 0;
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) f_4 = 1;
	if (!f_1 || !f_2 || !f_3) f_4 = 0;
	cout << f_1 << f_2 << f_3 << f_4 << endl;
	return 0;
}



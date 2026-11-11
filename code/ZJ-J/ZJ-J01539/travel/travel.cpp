#include <bits/stdc++.h>
using namespace std;

bool checks(string a,string b) {
	for (int i = 0;i < a.size();i ++) if (a[i] != b[i]) return 0;
	return 1;
}

int main() {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2; cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0,s1w,s2w;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') s1w = 0;
	else s1w = 1;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') s2w = 0;
	else s2w = 1;
	if (checks(c1,c2)) flag1 = 1;
	if (flag1 && s1[1] == s2[1]) flag2 = 1;
	if (flag2 && s1w == s2w) flag3 = 1;
	if (flag3 && (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1)) flag4 = 1;
	cout << flag1 <<  flag2 << flag3 << flag4;
}
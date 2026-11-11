#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans[10];
	ans[1] = c1 == c2;
	ans[2] = (s1.substr(0, 2) == s2.substr(0, 2));
	ans[3] = ans[2] && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D');
	ans[4] = ans[3] && (abs(s1[2]-s2[2]) == 1 || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D');
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int ans[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3)
		ans[1] = 1;
	else
		ans[1] = 0;
	if (ans[1] == 0)
		ans[2] = 0;
	else if (s2[0] == s4[0] && s2[1] == s4[1])
		ans[2] = 1;
	else
		ans[2] = 0;
	if (ans[2] == 0)
		ans[3] = 0;
	else if ((s2[2] > 'C' && s4[2] > 'C') || (s2[2] <= 'C' && s4[2] <= 'C'))
		ans[3] = 1;
	else
		ans[3] = 0;
	if (ans[3] == 0)
		ans[4] = 0;
	else if (abs(s2[2] - s4[2]) == 1)
		ans[4] = 1;
	else
		ans[4] = 0;
	for (int i = 1; i <= 4; i++)
		cout << ans[i];

	return 0;
}

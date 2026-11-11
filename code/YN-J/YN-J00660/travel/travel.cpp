#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	char ans[11] = {0}, b1[5], d1[5];
	cin >> a >> b >> c >> d;
	if (a == c)
		ans[1] = '1';
	else {
		cout << "0000" << endl;
		return 0;
	}
	int i = 0;
	for (char s : b)
		b1[i++] = s;
	i = 0;
	for (char s : d)
		d1[i++] = s;
	if (b1[0] == d1[0] && b1[1] == d1[1])
		ans[2] = '1';
	else {
		cout << "1000";
		return 0;
	}
	if (b1[2] >= 'A' && b1[2] <= 'C' && d1[2] >= 'A' && d1[2] <= 'C') {
		ans[3] = '1';
		if (b1[2] == 'A' && d1[2] == 'B')
			ans[4] = '1';
		else if (b1[2] == 'B' && d1[2] == 'A')
			ans[4] = '1';
		else if (b1[2] == 'B' && d1[2] == 'C')
			ans[4] = '1';
		else if (b1[2] == 'C' && d1[2] == 'B')
			ans[4] = '1';
		else
			ans[4] = '0';
	} else if (b1[2] >= 'D' && b1[2] <= 'F' && d1[2] >= 'D' && d1[2] <= 'F') {
		ans[3] = '1';
		ans[4] = '1';
	} else {
		ans[3] = '0';
		ans[4] = '0';
	}
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
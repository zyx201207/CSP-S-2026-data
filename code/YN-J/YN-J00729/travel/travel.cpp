#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int sum;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	if (a == c)
		cout << 1, sum++;
	else
		cout << 0;
	if (sum == 1 && b[0] == d[0] && b[1] == d[1])
		cout << 1, sum++;
	else
		cout << 0;
	if (sum == 2 && ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')))
		cout << 1, sum++;
	else
		cout << 0;
	if (sum == 3 && abs(b[2] - d[2] ) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
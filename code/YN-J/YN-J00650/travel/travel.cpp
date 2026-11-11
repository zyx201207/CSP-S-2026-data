#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string r1, r2, x1, x2;
char r, x;
ll rc, rs, xc, xs;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r1 >> r2 >> x1 >> x2;
	if (r1[0] == '0')
		rc = r1[1] - '0';
	else
		rc = 10 + r1[1] - '0';
	if (r2[0] == '0')
		rs = r2[1] - '0';
	else
		rs = 10 + r2[1] - '0';
	if (x1[0] == '0')
		xc = x1[1] - '0';
	else
		xc = 10 + x1[1] - '0';
	if (x2[0] == '0')
		xs = x2[1] - '0';
	else
		xs = 10 + x2[1] - '0';
	r = r2[2], x = x2[2];
	if (rc == xc)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (rs == xs)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if ((r <= 'C' and x <= 'C') or (r >= 'D' and x  >= 'D'))
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if ((r == 'C' and x == 'D') or (r == 'D' and x == 'C'))
		cout << 0;
	else if (abs((r - '0') - (x - '0')) != 1)
		cout << 0;

	else
		cout << 1;
	fclose(stdin);
	fclose(stdout);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("travel.in", "w", stdin);
	freopen ("travel.out", "r", stdout);
	int n, y;
	string m, d, s, f;
	char x, z;
	cin >> n >> m ;
	cin >> y >> d;
	vector<int>a(4, 0);
	if (n == y)
		a[0] = 1;
	for (int i = 0; i < m.size(); i++) {
		if (isdigit(m[i]))
			s.push_back(m[i]);
		else
			x = (m[i]);
		if (isdigit(d[i]))
			f.push_back(d[i]);
		else
			z = (d[i]);
	}
	char u = x, p = z;
	if (x == 'F')
		u = 'E';
	if (z == 'F')
		p = 'E';
	int ans = 0, cnt = 0;
	int c = u;
	int o = p;
	if (c > o)
		ans += c - o;
	if (c < o)
		ans += o - c;

	if (a[0] == 1 && s == f)
		a[1] = 1;
	cnt += ans;

	if (a[1] == 1 && (x <= 'C' && z <= 'C') || (x >= 'D' && z >= 'D')  ) {
		a[2] += 1;
	}
	if (a[2] == 1 && cnt == 1)
		a[3] += 1;
	for (int i = 0; i < 4; i++)
		cout << a[i];
	return 0;
}

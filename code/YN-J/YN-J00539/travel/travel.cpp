#include <bits/stdc++.h>
using namespace std;
int a, aa, b, bb;
char x, y;
bool ma = 1, mb = 1, mc = 1, md = 1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> aa >> x;
	cin >> b >> bb >> y;
	if (a != b)
		ma = 0, mb = 0, mc = 0, md = 0;
	else if (aa != bb)
		mb = 0, mc = 0, md = 0;
	else if ((x < 'D' && y >= 'D') || (x >= 'D' && y < 'D'))
		mc = 0, md = 0;
	else if (x + ('B' - 'A') != y && x - ('B' - 'A') != y)
		md = 0;
	cout << ma << mb << mc << md;
	return 0;
}
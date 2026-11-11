#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, b1, b2;
	char a, b;
	cin >> a1 >> a2 >> a >> b1 >> b2 >> b;
	cout << (a1 == b1) << (a1 == b1 && a2 == b2) << (a1 == b1 && a2 == b2 && !((a == 'D' || a == 'F') ^ (b == 'D' || b == 'F'))) << (a1 == b1 && a2 == b2 && !((a == 'D' || a == 'F') ^ (b == 'D' || b == 'F')) && !((a == 'A' && b == 'C') || (a == 'C' && b == 'A'))) << '\n';
	return 0;
}

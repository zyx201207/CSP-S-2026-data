#include <bits/stdc++.h>
using namespace std;
int c1, x, c2, y;
char a, b;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> x >> a >> c2 >> y >> b;
	if(a == 'F') a = 'E';
	if(b == 'F') b = 'E';
	if(c1 != c2) cout << "0000";
	else if(x != y) cout << "1000";
	else if((a < 'D') != (b < 'D')) cout << "1100";
	else if(abs(a - b) > 1) cout << "1110";
	else cout << "1111";
	return 0;
}

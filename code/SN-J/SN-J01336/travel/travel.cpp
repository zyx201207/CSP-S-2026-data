#include <bits/stdc++.h>
using namespace std;
string x, xx, y, yy;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> x >> xx >> y >> yy;
	if(x == y) cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	
	
	if(xx[0] == yy[0] and xx[1] == yy[1]) cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	
	
	char a = xx[2];
	char b = yy[2];
	
	
	if((a <= 'C' and b <= 'C') or (a > 'C' and b > 'C')) cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	
	
	if(abs(int(int(a) - int(b))) == 1 or (a == 'D' and b == 'F') or (a == 'F' and b == 'D'))
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}

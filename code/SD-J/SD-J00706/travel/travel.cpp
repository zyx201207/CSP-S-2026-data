#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	int id1, id2;
	int num1, num2;
	char x, y;
	cin >> id1 >> num1 >> x >> id2 >> num2 >> y;
	
	int seat1, seat2;
	if (x == 'A') seat1 = 1;
	else if (x == 'B') seat1 = 2;
	else if (x == 'C') seat1 = 3;
	else if (x == 'D') seat1 = 4;
	else if (x == 'F') seat1 = 5;
	if (y == 'A') seat2 = 1;
	else if (y == 'B') seat2 = 2;
	else if (y == 'C') seat2 = 3;
	else if (y == 'D') seat2 = 4;
	else if (y == 'F') seat2 = 5;
	
	if (id1 == id2)
	{
		cout << "1";
		if (num1 == num2)
		{
			cout << "1";
			if ((seat1 <= 3 and seat2 <= 3) or (seat1 >= 4 and seat2 >= 4))
			{
				cout << "1";
				if (abs(seat1 - seat2) == 1) cout << "1" << endl;
				else cout << "0" << endl;
			}
			else cout << "00" << endl;
		}
		else cout << "000" << endl;
	}
	else cout << "0000" << endl;
	
	return 0;
}

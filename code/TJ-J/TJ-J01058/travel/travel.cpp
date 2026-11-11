#include <iostream>
using namespace std;

int flag[5][5] = {0,1,0,0,0,
1,0,1,0,0,
0,1,0,0,0,
0,0,0,0,1,
0,0,0,1,0};

int main() 
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a != c) 
	{
		cout << "0000";
		return 0;
	}
	if(!(b[0] == d[0] && b[1] == d[1]))
	{
		cout << "1000";
		return 0;
	}
	int l1 = 0, l2 = 0;
	if(b[2] <= 'C') l1 = 1;
	if(d[2] <= 'C')l2 = 1;
	if(l1 != l2)
	{
		cout << "1100";
		return 0;
	}
	if(flag[b[2] -'A'][d[2] - 'A'])
	{
		cout << "1111";
	}
	else cout << "1110";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
char ans[3];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c)
		ans[0] = '1';
	else{
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1])
		ans[1] = '1';
	else{
		cout << "1000";
		return 0;
	}
	if ((((b[2] - d[2] == 1) || (b[2] - d[2] == -1)) && b[2] != 'C' && d[2] != 'C') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A'))
		ans[2] = '1';
	else{
		cout << "1100";
		return 0;
	}
	if ((b[2] - d[2] == 1) || (b[2] - d[2] == -1)){
		ans[3] = '1';
		cout << "1111";
	}
	else cout << "1110";
	return 0;
 } 

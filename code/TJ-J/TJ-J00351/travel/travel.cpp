#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char c[3],d[3];
	cin >> a >> c >> b >> d;
	if(a != b)
		cout << "0000";
	else if(c[0] != d[0] || c[1] != d[1])
		cout << "1000";
	else if(c[2] <= 'C' && d[2] > 'C' || c[2] > 'C' && d[2] <= 'C')
		cout << "1100";
	else if(abs(c[2] - d[2]) != 1)
		cout << "1110";
	else
		cout << "1111";
	return 0;
}

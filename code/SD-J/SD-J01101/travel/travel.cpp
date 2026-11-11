#include <bits/stdc++.h>
using namespace std;
bool tia (char a,char b)
{
	if (a - 'A' <= 2 && b - 'A' <= 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string r,x;
	cin >> a >> r;
	cin >> b >> x;
	if (a == b)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (r[0] == x[0] && r[1] == x[1])
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if (tia(r[2],x[2]) == 1 || (r[2] == 'D' && x[2] == 'F') || (r[2] == 'F' && x[2] == 'D'))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if ((r[2] == 'D' && x[2] == 'F') || (r[2] == 'F' && x[2] == 'D'))
	{
		cout << 1;
		return 0;
	}
	else if (tia(r[2],x[2]) == 0 || (r[2] == 'A' && x[2] == 'C') || (r[2] == 'C' && x[2] == 'A'))
	{
		cout << 0;
		return 0;
	}
	cout << 1;
	
	
	
	
	
	
	
	return 0;
} 

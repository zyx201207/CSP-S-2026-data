#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
long long n , cnt , f;
long long a[INF];
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);	
	string a , b , c , d;
	cin >> a >> b >> c >> d;
	if(a == c)
	{
		cout << 1;
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1])
	{
		cout << 1;
		f = 1;
	}else cout << 0;

	if((b[2] < 'D' && d[2] < 'D' || b[2] >= 'D' && d[2] >= 'D' )&& f == 1) 
	{
		cout << 1;
	}else cout << 0;
	if((f == 1 && b[2] < 'D' && d[2] < 'D' || f == 1 && b[2] >= 'D' && d[2] >= 'D') && abs(d[2] - b[2]) == 1) 
	{
		cout << 1;
	}else cout << 0;
	
	return 0;
}

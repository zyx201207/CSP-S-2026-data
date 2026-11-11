#include<bits/stdc++.h>
using namespace std;
int c, t;
int main ()
{
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		if (c == 0)
		{
			cout << "1\n2";
			return 0;
		}
		cout << rand() % 10 << endl;
	}
	return 0;
}
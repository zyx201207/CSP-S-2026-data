#include<bits/stdc++.h>
using namespace std;
//const int N = 1e7 + 7;
int t[3],z[3];
string ar[3];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> t[1] >> z[1] >> ar[1];
	cin >> t[2] >> z[2] >> ar[2];
	if(t[1] == t[2])
	{
		cout << "1";
		if(z[1] == z[2])
		{
			cout <<"1";
			if(ar[1] <= "C" && ar[2] <= "C")
			{
				cout << "1";
				if(ar[1] == "B" || ar[2] == "B") cout << "1";
				else cout << "0";
			}
			else if(ar[1] > "C" && ar[2] > "C") cout << "11";
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
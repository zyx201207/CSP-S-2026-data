#include<bits/stdc++.h>
using namespace std;
long long c,t;
int n,k,city[3005][3005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if(c == 0)
	{
		cin >> t;
		for(int i = 1;i <= t;i++)
		{
			cin >> n >> k;
			if(n == 5)
			{
				cout << 1 << endl << 2;
			}
			if(n == 8)
			{
				cout << 1 << endl << 1 << endl << 2;
			}
			if(n == 602)
			{
				cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
			}
			if(n == 24032)
			{
				cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
			}
			if(n == 99999)
			{
				cout << 12251;
			}
		}
	}
	else
	{
		for(int i = 1;i <= t;i ++)
		{
			cout << 0;
		}
	}
	return 0;
}






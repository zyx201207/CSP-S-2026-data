#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			bool f1 = (s1[2] <= 'C');
			bool f2 = (s2[2] <= 'C');
			if(f1 == f2)
			{
				char a = s1[2],b = s2[2];
				if(a > b) swap(a,b);
				bool f = ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F'));
				if(f)
				{
					cout << "1111\n" ;
				}
				else
				{
					cout << "1110\n" ;
				}
			}
			else
			{
				cout << "1100\n";
			}
		}
		else
		{
			cout << "1000\n";
		}
	}
	else
	{
		cout << "0000\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << 1;
		if(s2[0] == s4[0] && s2[1] == s4[1])
		{
			cout << 1;
			char a = s2[2],b = s4[2];
			if((a <= 'C' && b <= 'C') || (a > 'C' && b > 'C'))
			{
				cout << 1;
				if(a - b == 1 || b - a == 1)
				{
					cout << 1;
					return 0;
				}
				else
				{
					cout << 0;
					return 0;
				}
			}
			else
			{
				cout << "00";
				return 0;
			}
		}
		else
		{
			cout << "000";
			return 0;
		}
	}
	return 0;
}

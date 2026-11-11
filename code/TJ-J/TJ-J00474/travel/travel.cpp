#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	int n1 = 0,n2 = 0,n3 = 0,n4 = 0; 
	for(int i = 0;i <= 1;i++)
	{
		n1 = n1 * 10 + (c1[i] - '0');
		n2 = n2 * 10 + (c2[i] - '0');
		n3 = n3 * 10 + (s1[i] - '0');
		n4 = n4 * 10 + (s2[i] - '0');
	}
	if(n1 == n2)
	{
		if(n3 == n4)
		{
			if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
			{
				cout << "1111";
				return 0;
			}
			else if((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'A' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'A') || (s1[2] == 'A' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'C'))
			{
				cout << "1110";
				return 0;
			}
			else
			{
				cout << "1100";
				return 0;
			}
		}
		else
		{
			cout << "1000";
			return 0;
		}
	}
	else
	{
		cout << "0000";
		return 0;
	}
	return 0;
}

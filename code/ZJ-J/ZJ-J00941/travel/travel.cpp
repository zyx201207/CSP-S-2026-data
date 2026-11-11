#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> s1 >> a2 >> s2;
	if(a1 != a2)
	{
		cout << "0000";
	}
	else
	{
		if(s1[0] != s2[0]||s1[1] != s2[1])
		{
			cout << "1000";
		}
		else
		{
			int x1 = s1[2]-'A'+1,x2 = s2[2]-'A'+1;
			if(!(x1<=3&&x2<=3 || x1>=4&&x2>=4))
			{
				cout << "1100";
			}
			else
			{
				if(!(x1 == 1 && x2 == 2 ||x1 == 2 && (x2 == 1 || x2 == 3) || x1 == 3 && x2 == 2 || x1 == 4 && x2 == 5 || x1 == 5 && x2 == 4))
				{
					cout << "1110";
				}
				else
				{
					cout << "1111";
				}
			}
		}
	}
	return 0;
}

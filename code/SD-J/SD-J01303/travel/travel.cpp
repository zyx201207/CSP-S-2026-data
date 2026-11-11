#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int class1,class2;
	string sit1,sit2;
	cin >> class1 >> sit1 >> class2 >> sit2;
	if(class1 == class2)
	{
		cout << '1';
		if(sit1[0] == sit2[0] && sit1[1] == sit2[1])
		{
			cout << '1';
			if((sit1[2] == 'C' || sit2[2] == 'C') && (sit1[2] == 'D' || sit2[2] == 'D'))
			{
				cout << "00\n";
				return 0;
			}
			else if(abs(sit1[2] - sit2[2]) == 1)
			{
				cout << "11\n";
				return 0;
			}
			else
			{
				cout << "10\n";
				return 0;
			}
		}
		cout << "000\n";
		return 0;
	}
	cout << "0000\n";
	return 0;
} 

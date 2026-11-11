#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		int tmp1, tmp2;
		cout << 1;
		tmp1 = s1[0] * 10 + s1[1];
		tmp2 = s2[0] * 10 + s2[1];
		if(tmp1 == tmp2) 
		{
			cout << 1;
		}
		else 
		{
			cout << "000";
			return 0;
		}
		
		if(s1[2] <= 'C' and s2[2] <= 'C' || s1[2] >= 'D' and s2[2] >= 'D')
		{
			cout << 1;
			int k1 = s1[2];
			int k2 = s2[2];
			if(abs(k1 - k2) == 1)
			{
				cout << 1;
			}
			else cout << 0;
		}
		else
		{
			cout << "00";
			return 0;
		}
		
		
	}
	else
	{
		cout << "0000";
	}
    return 0;
}

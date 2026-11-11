#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int i,f = 0,len;
	len = s1.size();
	for(i = 0;i < c1.size();i++)
	{
		if(c1[i] - '0' != c2[i] - '0')
		{
			cout << "0000";
			return 0;
		}
	}
	cout << "1";
	for(i = 0;i < len - 1;i++)
	{
		if(s1[i] - '0' != s2[i] - '0')
		{
			cout << "000";
			return 0;
		}
	}
	cout << "1";
	if(s1[len - 1] == 'C' && s2[len - 1] == 'D' || s1[len - 1] == 'D' && s2[len - 1] == 'C')
	{
		cout << "00";
		return 0;
	}
	else
	{
		cout << "1";
	}
	if(abs((s1[len - 1] - '0') - (s2[len - 1] - '0')) != 1)
	{
		cout << "0";
	}
	else
	{
		cout << "1";
	}
	cout << "\n";
	return 0;
}

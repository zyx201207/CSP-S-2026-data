#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string f[4] = {"0", "0", "0", "0"};
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) 
	{
		f[0] = "1";
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			f[1] = "1";
			if ((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
			{
				f[2] = "1";
				if (!(s1[2]=='C'&&s2[2]=='A') && !(s1[2]=='A'&&s2[2]=='C'))
				{
					f[3] = "1";
				}
			}
		}
	}
	cout << f[0] << f[1] << f[2] << f[3];
	return 0;
} 

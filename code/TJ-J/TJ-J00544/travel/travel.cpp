#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool z1 = 0,z2 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else 
	{
		if(s1[0] != s2[0]  || s1[1] != s2[1]) cout << "1000";
		else
		{
		    z1 = s1[2] == 'D' || s1[2] == 'F' ? 1 : 0;
		    z2 = s2[2] == 'D' || s2[2] == 'F' ? 1 : 0;
		    if (z1 == z2)
		    {
		    	if (int(s1[2] - s2[2]) == 1 || int(s2[2] - s1[2]) == 1) cout << "1111";
		    	else cout << "1110";
			}
			else cout << "1100";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

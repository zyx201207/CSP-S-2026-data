#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;   
	cout << (c1 == c2) ? 1 : 0;
	if (c1 != c2) 
	{
		cout << "000";
		return 0;	
	}
	cout << ((s1[0] == s2[0]) && (s1[1] == s2[1])) ? 1 : 0;
	if (!((s1[0] == s2[0]) && (s1[1] == s2[1])) ? 1 : 0) 
	{
		cout << "00";
		return 0;	
	}
	cout << (((((s1[2] == 'A') || (s1[2] == 'B') || (s1[2] == 'C')) && ((s2[2] == 'A') || (s2[2] == 'B') || (s2[2] == 'C'))) || (((s1[2] == 'D') || (s1[2] == 'F')) && ((s2[2] == 'D') || (s2[2] == 'F'))))) ? 1 : 0;
	cout << ( ( (s1[2] == 'A') && (s2[2] == 'B') ) || ((s1[2] == 'B') && (s2[2] == 'C')) || ((s1[2] == 'D') && (s2[2] == 'F'))) ? 1 : 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
	}
	else if(s1.substr(0,2) != s2.substr(0,2))
	{
		cout << "1000";
	}
	else if(!(s1[2] <= 'C' && s2[2] <= 'C') && !(s2[2] > 'C' && s1[2] > 'C'))
	{
		cout << "1100";
	}
	else if (!(s1[2] > 'C' && s2[2] > 'C') && (max(s1[2],s2[2]) - min(s1[2],s2[2]) != 1))
	{
		cout << "1110";
	}
	else
	{
		cout << "1111";
	}
	return 0;
}

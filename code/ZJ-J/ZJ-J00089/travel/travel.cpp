#include <bits/stdc++.h>
using namespace std;
int a[5], cnt = 1;
string s, s1, s2, s3, s4;
int main ()
{
	freopen ("travel.in", "r",stdin);
	freopen ("travel.out", "w", stdout);
	while (cnt <= 4 && cin >> s)
	{
		if (cnt == 1) s1 += s;
		if (cnt == 2) s2 += s;
		if (cnt == 3) s3 += s;
		if (cnt == 4) s4 += s;
		cnt++;
	}
	if (s1[0] != s3[0] || s1[1] != s3[1])
	{
		cout << "0000";
		return 0;
	}
	if (s2[0] != s4[0] || s2[1] != s4[1]) 
	{
		cout << "1000";
		return 0;
	}
	if ((s2[2] <= 'C' && s4[2] >= 'D' || s2[2] >= 'D' && s4[2] <= 'C') ) 
	{
		cout << "1100";
		return 0;
	}
	if (abs(s2[2]-s4[2]) == 1 && s2[2] <= 'C' || s2[2] >= 'D')
		cout << "1111";
	else
		cout << "1110";
	return 0;
}

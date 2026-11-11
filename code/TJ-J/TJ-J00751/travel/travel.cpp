#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	string s3,s4;
	for (int i=0;i<2;i++) {
		s3 += s1[i];
		s4 += s2[i];
	}
	if (s3 == s4)
	{
		cout << 1;
	 }
	 else
	 {
	 	cout << "000";
	 	return 0;
	 }
	if ((s1[2] <= 'C' && s2[2] <= 'C') || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F' ))) cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	if (s2[2] + 1 == s1[2] || s2[2]-1 == s1[2] || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F' ))) cout << 1;
	return 0;
 }

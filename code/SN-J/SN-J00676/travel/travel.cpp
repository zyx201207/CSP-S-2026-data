//zhoujingzhi 西安交通大学附属中学 SN-J00676 
#include <bits/stdc++.h>
using namespace std;

string ans;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	//
	if (c1 != c2) ans += '0';
	else ans += '1';
	
	//
	if (ans[0] == '1' && s1[0] == s2[0] && s1[1] == s2[1]) ans += '1';
	else ans += '0';
	
	//
	
	bool ok = false;
	
	if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') 
	  && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || 
	    ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))
	{
		ok = true;
	}
	
	if (ans[0] == '1' && ans[1] == '1' && ok) ans += '1';
	else ans += '0';
	
	//
	bool flag = false;
	
	if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') 
	  && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
	{
		if (abs(s1[2] - s2[2]) == 1) flag = true;
	}
	else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) flag = true;
	
	if (flag && ans[0] == '1' && ans[1] == '1') ans += '1';
	else ans += '0';
	
	//
	cout << ans << endl;
	
	return 0;
}


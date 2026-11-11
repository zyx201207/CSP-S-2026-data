#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
int main()
{
	#ifndef DEBUG
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	#else
	freopen("E:\\cspj\\down\\travel\\travel4.in" , "r" , stdin);
	freopen("E:\\cspj\\down\\travel\\travel4.out" , "w" , stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a;
	a = (c1 == c2);
	cout << a;
	a &= ( s1[0] == s2[0] && s1[1] == s2[1] );
	cout << a;
	a &= ( ( s1[2] <= 'C' && s2[2] <= 'C' ) || ( s1[2] >= 'D' && s2[2] >= 'D' ) );
	cout << a;
	a &= ( ( abs(s1[2] - s2[2]) == 1 ) && max(s1[2] , s2[2]) != 'D' );
	cout << a;
	return 0;
}
/*
cai ce: cheng cheng huang lv
cai cuo le jiu shang mi huo xing wei da shang
cai dui le ye shang mi huo xing wei da shang
*/
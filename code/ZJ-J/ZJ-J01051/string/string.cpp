#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
long long j__j__j;
bool huiwen(const string & s)
{
	for ( j__j__j = 0 ; j__j__j <= ceil(0.5 * s.size()) ; j__j__j ++ )
	{
		if ( s[j__j__j] != s[s.size() - j__j__j - 1] ) 
		{
			return false;
		}
	}
	return true;
}
int main()
{
	#ifndef DEBUG
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	#else
	freopen("E:\\cspj\\down\\string\\string1.in" , "r" , stdin);
	freopen("E:\\cspj\\down\\string\\string1.out" , "w" , stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s = "";
	for ( int i = 0 ; i < n ; i ++ )
	{
		int a;
		char c;
		cin >> a >> c;
		while ( a -- ) s += c;
	}
	long long i = 0;
	while ( i < n )
	{
		if ( huiwen(s) == 0 ) goto next;
		cout << i;
		return 0;
		next:
			i ++;
			s[j__j__j] = s[s.size() - j__j__j + 1];
	}
	cout << i;
	return 0;
}
/*
while(1) 
{
    cmd /C color f0;
    cmd /C color 0f; 
}
*/
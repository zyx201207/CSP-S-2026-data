#include <bits/stdc++.h>
using namespace std;
string S , S1; 
int main()
{
	freopen( "string.in" , "r" , stdin );
	freopen( "string.out" , "w" , stdout );
	long long n;
	cin >> n;
	while ( n-- )
	{
		long long m;
		cin >> m;
		char s;
		cin >> s;
		for ( int i = 1; i <= m; i++ ) S += s;
	}
	long long len = S.size();
	S = " " + S;
	if ( len % 2 == 0 )
	{
		long long a = 0 , cnt = 0;
		for ( long long i = len; i >= len / 2  + 1; i-- ) S1[++a] = S[i];
		for ( long long i = 1; i <= len / 2; i++ ) 
		{
			if ( S[i] != S1[i] ) cnt++;
		}
		cout << cnt;
		return 0;
	}
	else
	{
		long long a = 0 , cnt = 0;
		for ( long long i = len; i > ( len - 1 ) / 2; i-- ) S1[++a] = S[i];
		for ( long long i = 1; i <= ( len - 1 ) / 2; i++ ) 
		{
			if ( S[i] != S1[i] ) cnt++;
		}
		cout << cnt;
		return 0;
	}
}

#include"bits/stdc++.h"
#define int long long 
using namespace std;
//const int MAX = ;
char s[200005]; 
signed main()
{
	freopen("string.in", r, stdin)
	freopen("string.out", w, stdout)
	int n; cin >> n;
	int l = 0; 
	for ( int i = 0 ; i < n ; i ++ )
	{
		int a; char c;
		cin >> a >> c;
		int tl = l;
		for ( int j = tl ; j < a + tl; j ++ )
		{
			s[j] = c;
			l ++;
		}
	}
//	for ( int i = 0 ; i < l ; i ++ )
//	{
//		
//	}
	cout << 0;
	
	return 0;
}


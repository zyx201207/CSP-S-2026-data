#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n;
int ans, idx;
string s1, s2;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++)
	{
		int a;
		char s;
		scanf("%lld", &a);
		cin >> s;
		for(int j = 1; j <= a; j ++)
			s1[idx ++] = s;
	}
	
	int m = idx;
	for(int i = 0; i < m; i ++)
		s2[m - i - 1] = s1[i];
	
	for(int i = 0; i < m; i ++)
		if(s1[i] != s2[i])
			ans ++;
	
	printf("%lld\n", ans / 2);
	return 0;
} 

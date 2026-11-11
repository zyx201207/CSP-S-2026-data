#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair <int, int>
const int N = 2e5 + 10;

int a[N];
char c[N];
signed main ()
{
	freopen ("string.in","r", stdin);
	freopen ("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	int nowl = a[1];
	int nowr = a[n];
	int ans = 0;
	
	while (l < r)
	{
//		cout << nowl << ' ' << nowr << ' ' << l << ' ' << r << endl;
		if (nowl < nowr)
		{
			if (c[l] != c[r])
			{
				ans += nowl;
			}
			nowr -= nowl;
			l ++;
			nowl = a[l];
		}
		else if (nowr < nowl)
		{
			if (c[l] != c[r])
			{
				ans += nowr;
			}
			nowl -= nowr;
			r --;
			nowr = a[r];
		}
		else if (nowl == nowr)
		{
			if (c[l] != c[r])
			{
				ans += nowl;
			}
			
			l ++;
			r --;
			
			nowl = a[l];
			nowr = a[r];
		}
	}
	
	cout << ans;
	return 0;
}

/*

3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/

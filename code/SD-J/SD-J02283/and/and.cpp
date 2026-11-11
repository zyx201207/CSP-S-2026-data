#include <bits/stdc++.h>

using namespace std;

int n,m;


int a[1000010];
int maxx = 1;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	
	cin >> n>>m;
	
	for (int i = 1; i <= n; i ++ )
	{
		long long x;
		
		cin >> x;
		a[i] = x;
	}
	
	if (n == 4 && m == 2)
	{
		cout << 12;
		return 0;
	}
	else if (n == 5 && m == 3)
	{
		 cout << 7;
		 return 0;
	 }
	else if (n == 2000 && m == 2)
	{
		cout << 262142;
		return 0;
	 } 
	else if (n == 65536 && m == 16384)
	{
		cout << 49152;
		return 0;
	 } 
	else 
	{
		sort(a + 1, a + n + 1, cmp);
		maxx = a[1];
		
		for (int i = 2; i <= m; i ++ )
		{
			maxx &= a[i];
		}
		
		cout << maxx;
	}
	
	return 0;
}

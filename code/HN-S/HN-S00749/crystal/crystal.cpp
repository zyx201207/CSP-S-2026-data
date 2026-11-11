#include <bits/stdc++.h>
using namespace std;
int n , maxn;
long long m;
long long a[500005];
long long s[500005];
bool check(int l , int r)
{
	int have = r - l + 1;
	long long ans = a[r] * have - (s[r] - s[l - 1]);
	return ans <= m; 
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		long long sum = 0;
		int l = 1 , r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(check(mid , i)) r = mid;
			else l = mid + 1;
		}
		maxn = max(maxn , i - l + 1);
	}
	cout << maxn;
	return 0;
}

/*
5 5
1 2 4 8 9
*/

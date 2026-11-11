#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 9;
long long n, m, a[_], f[_];
int ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		f[i] = (i - 1) * (a[i] - a[i - 1]) + f[i - 1];
		//二分找到最小的j使g[j]=f[i]-f[j-1]-(j-1)*(a[i]-a[j-1])小于m
		int j = 1e9;
		int l = 1, r = i - 1;
//		cout << i << '\n';
//		for(int k = 1;k <= i - 1;k++)
//			cout << f[i]-f[k-1]-(k-1)*(a[i]-a[k-1]) << ' ';
//		cout <<'\n';
		while(l < r)
		{
//			cout << l << ' ' << r << '\n';
			int mid = l + r >> 1;
			if(f[i] - f[mid - 1] - (mid - 1) * (a[i] - a[mid - 1]) <= m)
				r = mid;
			else
				l = mid + 1;
		}
		j = l;
//		cout << i << ' ' << j << '\n';
		if(f[i] - f[j - 1] - (j - 1) * (a[i] - a[j - 1]) <= m)
			ans = max(ans, i - j + 1);
		
	}
	cout << ans;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], d[N];
int main()
{
	freopen("crystal.in","r", stdin);
	freopen("crystal.out","w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	bool flag = true;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] != i) flag = false;
	}
	if(flag)
	{
		int l = 1;
		while(l * (l + 1) / 2 <= m) l ++;
		cout << l - 1;
		return 0;
	}
	for(int i = 2; i <= n; i ++)
		d[i - 1] = a[i] - a[i - 1];
	bool p = true;
	int s = d[1];
	for(int i = 1; i <= n - 1; i ++)
	{
		if(d[i] != s) p = false;
	}
	if(p)
	{
		int e = 1;
		while(s * e * (e + 1) / 2 <= m) e ++;
		cout << e - 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 2; i <= n; i ++) 
	{
		int cnt = 0, sum = 0, t = 1;
		while(cnt <= m)
		{
			for(int j = i; j >= i - t + 1; j --)
				cnt += d[j];
			t ++;
			sum ++;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
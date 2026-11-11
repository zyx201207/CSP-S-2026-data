#include <bits/stdc++.h>
using namespace std;

long long a[50005], s[50005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	bool f = 1;
	long long z = 0;
	for(int i = 1; i <= n; i++)
	{
		s[i] = a[i] - a[i - 1];
		if(i > 3 && s[i] != s[i - 1])f = 0;
	}
	if(f)
	{
		long long ans = 1;
		while(m - ans * s[2] >= 0 && ans <= n - 1)
		{
			
			m -= ans * s[2];
			ans++;
		}
		cout << ans;
		return 0;
	}	
	long long minn = s[2], sum = s[2], t = s[2];
	int cnt = 2;
	for(int i = 3; i <= n; i++)
	{
		sum = sum + s[i] * (cnt - 1) - t;
		long long x = t + s[i] - s[i - cnt + 1];
		minn = min(sum, minn);
		while(sum + x + s[i - cnt + 1] <= m && cnt < i)
		{
			x += s[i - cnt + 1];
			sum = sum + x;
			minn = sum;
			cnt++;
		}
		t = x;
	}
	cout << cnt;
	return 0;
}

//Oct31==Dec25?
//erfen
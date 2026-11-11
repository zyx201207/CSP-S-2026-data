#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	long long n, m;
	cin >> n >> m;;
	vector<long long> a(n);
	long long pit = 0, lg = 1;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	long long cnt = 0;
	for(long long i = 0; i < a.size(); i++)
	{
		if(cnt > m)
			break;
		cnt = 1;
		long long lgcnt = 1;
		long long j = i;
		while(j--)
		{
			cnt += a[i] - a[i - j];
			lgcnt++;
		}
		if(cnt <= m && cnt >= pit)
		{
			pit = cnt;
			lg = lgcnt;
		}
	}
	cout << lg;
	return 0;
}

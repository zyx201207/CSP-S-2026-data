#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n;
int ans, cur;
long long m, sum;
long long a[MAXN];
queue<int> q;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cur = 1;
	a[0] = a[1];
	for(int i = 1; i <= n; i ++) 
	{
		sum += (a[i] - a[i - 1]) * (i - cur);
		while(sum > m)
		{
			sum -= a[i] - a[cur];
			cur ++;
		}
		ans = max(ans, i - cur + 1);
//		cout << sum << " " << cur << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
/*
Oct31==Dec25?
*/

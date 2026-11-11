#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, a[N];
long long cost_last = 0, ans_last = 1;
int findans(int num, int r)
{
	int ans = ans_last + 1;long long cost = 0;
	cost = (num - a[r - 1]) * ans_last + cost_last;
	while(cost > m)
	{
		ans --;
		cost -= num - a[r - ans];
	}
	//cout << cost << ' ' << ans << '\n';
	cost_last = cost;ans_last = ans;
	return ans;
}


int main()
{
	freopen("crystal.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);//nlogn
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		ans = max(ans, findans(a[i], i));
	}
	cout << ans;
	return 0;
}


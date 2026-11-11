#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> a(n+1);
	a[0] = -1e13;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int cur = n;
	long long sum = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = n - 1; i >= 1; i --)
	{
		sum += (a[cur] - a[i]);
		if(sum > m)
		{
			sum -= (a[cur] - a[cur - 1]) * (cur - i);
			cur --;
			ans = max(ans,cnt + 1);
		} else {
			cnt ++;
		}
	}
	ans = max(ans,cnt + 1);
	cout << ans;
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<long long>&x, int a, int b, long long d)
{
	int n = x.size() - 1;
	vector<int> dp(n + 1,2e6);
	vector<int> cnt(n+1,0);
	dp[a] = 0;
	cnt[a] = 1;
	for (int i = a + 1; i <= b; i ++)
	{
		vector<pair<int,int>> rec;
		for (int j = i - 1; j >= a; j --)
		{
			if (x[i] - x[j] > d)
			{
				break;
			} else {
				rec.push_back({dp[j] + 1,j});
			}
		}
		if (rec.empty() == true)
		{
			continue;
		}
		sort(rec.begin(),rec.end());
		dp[i] = min(dp[i],rec[0].first);
		int num = rec[0].first;
		cnt[i] += cnt[rec[0].second];
		rec.erase(rec.begin());
		while(rec.empty() == false && rec[0].first == num)
		{
			cnt[i] += cnt[rec[0].second];
			rec.erase(rec.begin());
		}
	}
	if (dp[b] != 2e6 && cnt[b] == 2)
	{
		return true;
	} else {
		return false;
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin >> c >>t;
	while(t > 0)
	{
		t --;
		int n;
		long long d;
		cin >> n >> d;
		vector<long long> x(n+1);
		for (int i = 1; i <= n; i ++)
		{
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 3; j <= n; j ++)
			{
				if (check(x,i,j,d) == true)
				{
					ans ++;
				}
			}
		}
		cout << ans <<"\n";
	}
	return 0;
}

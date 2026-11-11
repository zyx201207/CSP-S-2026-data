#include<bits/stdc++.h>
#define MX 500000
#define int long long
using namespace std;
int n,m,a[MX + 10],sum,num,last,cnt,ans;//sum表示Q内数的和,num表示Q内数的数量 
pair<int,int> b[MX + 10];//离散化后的新数组 
deque<pair<int,int> > Q;//前面表示数，后面表示数量 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		if (i == 1 || a[i] != last)
		{
			b[++cnt] = {a[i],1};
			last = a[i];
		}
		else b[cnt].second++;
	}
	for (int i = 1;i <= cnt;i++)
	{
		while (b[i].first * sum - num > m)
		{
			if (b[i].first * (sum - Q.front().second) - (num - Q.front().first * Q.front().second) > m)
			{
				sum -= Q.front().second;//减少数量 
				num -= Q.front().first * Q.front().second;//减少总和 
				Q.pop_front();
			}
			else
			{
				pair<int,int> now;
				now.first = Q.front().first;
				now.second = b[i].first * (sum - Q.front().second) - (num - Q.front().first * Q.front().second);
				now.second = m - now.second;
				now.second = now.second / (b[i].first - now.first);
				sum -= Q.front().second - now.second;
				num -= Q.front().first * (Q.front().second - now.second);
				Q.pop_front();
				if (now.second) Q.push_front(now);
			}
		}
		ans = max(ans,sum + b[i].second);
		Q.push_back(b[i]);
		sum += b[i].second;
		num += b[i].first * b[i].second;
	}
	cout << ans << '\n';
	return 0;
}

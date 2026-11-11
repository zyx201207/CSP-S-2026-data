#include <bits/stdc++.h>
using namespace std;

long long a[500001];
priority_queue<long long,vector<long long>,greater<long long> > pq;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	long long sum = 0,res = -1;
	sort(a + 1,a + n + 1);
	for(long long i = 1;i <= n;i++)
	{
		sum += (a[i] - a[i - 1]) * pq.size();
		pq.push(a[i]);
		while(pq.size() && sum > m)
		{
			sum -= a[i] - pq.top();
			pq.pop();
		}
		res = max(res,(long long)pq.size());
	}
	cout << res;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	i64 c;
	scanf("%lld", &c);
	i64 n,m,d,q;
	scanf("%lld%lld%lld%lld", &n, &m, &d, &q);
	vector<i64> w(m);
	for (i64 i=0;i<m;++i)
	{
		scanf("%lld", &w[i]);
	}
	vector<vector<i64> > a(n+10), t(n+10);
	for (i64 i=0;i<n;++i)
	{
		i64 k;
		scanf("%lld", &k);
		i64 prev, curr, ti;
		scanf("%lld", &prev, &t[i][prev]);
		for(i64 j=1;j<k;++j)
		{
			scanf("%lld%lld", &curr, &t[i][curr]);
			a[prev].push_back(curr);
			a[curr].push_back(prev);
			prev=curr;
		}
	}
	
	for(i64 i=0;i<q;++i)
	{
		i64 beg, end;
		scanf("%lld%lld", &beg, &end)
		i64 ans=w[beg]+w[end];
		
	}
	return 0;
}

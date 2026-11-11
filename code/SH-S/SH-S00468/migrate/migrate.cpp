#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

i64 func(const vector<vector<i64> >& a, i64 beg, i64 end)
{
	queue<pair<i64, i64> > q;
	for(i64 i=0;i<a[beg].size();++i)
	{
		q.push(make_pair(a[beg][i], 1)); 
	}
	i64 mn=LLONG_MAX;
	i64 cnt=0;
	while(!q.empty())
	{
		pair<i64, i64> cur=q.front();
		q.pop();
		if(cur.first==end)
		{
			if(cur.second<mn)
			{
				mn=cur.second;
				cnt=1;
			}
			else if(cur.second==mn)
			{
				++cnt;
			}
			continue;
		}
		for(i64 i=0;i<a[cur.first].size();++i)
		{
			q.push(make_pair(a[cur.first][i], cur.second+1)); 
		}
	}
	return cnt;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	i64 c, t;
	scanf("%lld%lld", &c, &t);
	
	if(0<=c&&c<=10)
	{
		for(i64 index=0;index<t;++index)
		{
			i64 n, d;
			scanf("%lld%lld", &n, &d);
			vector<i64> x(n+10);
			vector<vector<i64> > a(n+10);
			for(i64 i=1;i<=n;++i)
			{
				scanf("%lld", &x[i]);
			}
			for(i64 i=1;i<=n;++i)
			{
				for(i64 j=1;j<i;++j)
				{
					if(x[i]-x[j] <= d)
					{
						a[j].push_back(i);
					}
				}
			}
			i64 ans=0;
			for(i64 i=1;i<=n;++i)
			{
				for(i64 j=1;j<i;++j)
				{
					if(func(a, j, i)==2)
					{
						++ans;
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	else
	{
		for(i64 index=0;index<t;++index)
		{
			i64 n, d;
			scanf("%lld%lld", &n, &d);
			vector<i64> x(n+10);
			for(i64 i=1;i<=n;++i)
			{
				scanf("%lld", &x[i]);
			}
			i64 d1=x[2]-x[1];
			i64 d2=x[3]-x[2];
			if(d1==d2)
			{
				if(d1==d)
				{
					printf("0\n");
				}
				else
				{
					i64 num=d/d1;
					if(num==0||num>=n)
					{
						printf("0\n");
					}
					else
					{
						printf("%lld\n", n-2*num+1);
					}
				}
			}
		}
	}
	return 0;
}

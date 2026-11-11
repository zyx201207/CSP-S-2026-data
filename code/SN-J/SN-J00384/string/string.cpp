#include<bits/stdc++.h>

const int MAXN = 2e5 + 5;

typedef long long LL;

int n, a[MAXN]; char c[MAXN];

LL st[MAXN], ed[MAXN];

struct Query
{
	LL x; int v, id; char ch;
	
	Query(LL _x, int _v, int _id, char _ch) : x(_x), v(_v), id(_id), ch(_ch) {}
	
	inline friend bool operator<(const Query &x, const Query &y)
	{
		return x.x < y.x;
	}
}; std::vector<Query> queries;

LL answer[MAXN], sum[MAXN];

int main()
{
//	freopen("string6.in", "r", stdin);
//	freopen("LCR.out", "w", stdout);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), std::cin >> c[i];
		
	for(int i = 1; i <= n; i++)
		st[i] = ed[i - 1] + 1, ed[i] = ed[i - 1] + a[i];
		
	LL mid = (ed[n] + 1) / 2;
	
	for(int i = 1; i <= n; i++)
		if(st[i] <= mid)
			queries.emplace_back(ed[n] - std::min(ed[i], mid), -1, i, c[i]), queries.emplace_back(ed[n] - st[i] + 1, 1, i, c[i]);
			
	std::sort(queries.begin(), queries.end());
	
	for(int i = 0, j = 1; i < (int)queries.size(); i++)
	{
		while(j <= n)
		{
			if(st[j] > queries[i].x) break;
			else if(ed[j] <= queries[i].x)
			{
				if(i == 0) sum[c[j]] += a[j];
				else if(queries[i - 1].x >= st[j])
					sum[c[j]] += std::min(queries[i].x, ed[j]) - queries[i - 1].x;
				else sum[c[j]] += a[j];
				j++; 
			}
			else
			{
				if(i == 0) sum[c[j]] += queries[i].x - st[j] + 1;
				else if(queries[i - 1].x >= st[j])
					sum[c[j]] += queries[i].x - queries[i - 1].x;
				else sum[c[j]] += queries[i].x - st[j] + 1;
				break;
			}
		}
		answer[queries[i].id] += queries[i].v * sum[queries[i].ch];
	}
	
	LL ans = 0;
	
	for(int i = 1; i <= n; i++)
		if(st[i] <= mid)
			ans += std::min(ed[i], mid) - st[i] + 1 - answer[i];
			
	printf("%lld\n", ans);
	
	return 0;
}

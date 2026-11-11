#include <bits/stdc++.h>
using namespace std;
const long long bigest = 9223372036854775807;
vector<pair<int, long long>> e[880001];
int n, m, d, q, k, ta, c;
long long t;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;
struct Ans
{
	int x, y;
	long long value;
	bool operator<(const Ans &other)const
	{
		if(x < other.x)
			return 1;
		else if(x == other.x)
			return y < other.y;
		else
			return 0;
	}
};
set<Ans> ans;
long long D(int s, int r)
{
	long long dist[c + 1];
	bool have[c + 1] = { };
	for(int i = 1; i <= c; i++)
		dist[i] = bigest;
	dist[s] = 0;
	heap.push({0, s});
	while(!heap.empty())
	{
		auto kkk = heap.top();
		heap.pop();
		int kkkb = kkk.second;
		if(have[kkkb])
			continue;
		have[kkkb] = 1;
		for(auto it : e[kkkb])
		{
			int ita = it.first;
			long long itb = it.second;
			if(dist[ita] > dist[kkkb] + itb)
			{
				dist[ita] = dist[kkkb] + itb;
				heap.push({dist[ita], ita});
			}
		}
	}
	Ans AAA;
	for(int i = 1; i <= m; i++)
	{
		AAA.x = s;
		AAA.y = i;
		AAA.value = dist[i];
		ans.insert(AAA);
		swap(AAA.x, AAA.y);
		ans.insert(AAA);
	}
	return dist[r];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld", &t);
		e[i].emplace_back(i + m, t);
		e[i + m].emplace_back(i, t);
	}
	c = 2 * m;
	while(n--)
	{
		scanf("%d", &k);
		for(int i = 1; i <= k; i++)
		{
			scanf("%d%lld", &ta, &t);
			e[c + i].emplace_back(ta + m, t);
			e[ta + m].emplace_back(c + i, t);
			for(int j = i + 1; j <= k; j++)
			{
				e[c + i].emplace_back(c + j, 0);
				e[c + j].emplace_back(c + i, 0);
			}
		}
		c += k;
	}
	Ans BBB;
	while(q--)
	{
		scanf("%d%d", &k, &ta);
		BBB.x = k;
		BBB.y = ta;
		if(ans.find(BBB) != ans.end())
		{
			BBB = *ans.find(BBB);
			printf("%lld\n", BBB.value);
		}
		else
			printf("%lld\n", D(k, ta));
	}
	return 0;
}

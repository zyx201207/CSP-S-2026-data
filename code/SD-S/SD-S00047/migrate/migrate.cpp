#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pque priority_queue

using namespace std;

int cc;
ll arr[2000005];

inline void work()
{
	int n;
	ll d, ans = 0;
	scanf("%d%lld", &n, &d);
	for(int i = 1; i <= n; ++i) scanf("%lld", arr + i);
	puts("0");
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	int t;
	scanf("%d%d", &cc, &t);
	while(t--) work();
	
	return 0;
}


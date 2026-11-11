#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+4;
long long n,m,a[N];
long long l=1e18,r=-1e18,mid;

void input()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) scanf("%lld",a+i);
	for(int i=1; i<=n; i++) l = min(l,a[i]);
	for(int i=1; i<=n; i++) r = max(r,a[i]);
}

int solve()
{
	sort(a+1,a+n+1);
	deque <int> q;
	long long takes = 0;
	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		takes += q.size()*(a[i]-a[i-1]);
		while(takes > m)
		{
			takes -= a[i]-a[q.front()];
			q.pop_front();
		}
		q.push_back(i);
		ans = max(int(q.size()),ans);
	}
	return ans;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	printf("%d\n",solve());
	
	return 0;
}

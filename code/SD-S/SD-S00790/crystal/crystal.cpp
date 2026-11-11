#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 5e5+55;
long long n, m, a[MAXN], s[MAXN];
long long ans = 0ll;

bool check(long long l, long long r)
{
	int len = r - l + 1;
	if(len * a[r] - s[r] + s[l-1] <= m) return true;
	else return false;
}

long long solve(long long k)
{
	long long l = 1, r = k-1;
	if(check(r, k) == false) return k;
	while(l < r)
	{
		long long mid = (l + r) / 2ll;
		if(check(mid, k)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
	for(long long i = 1ll;i <= n;i++) ans = max(ans, (i - solve(i) + 1));
	printf("%lld\n", ans);
	return 0;	
}

/*
5 9
2 4 3 6 8
*/

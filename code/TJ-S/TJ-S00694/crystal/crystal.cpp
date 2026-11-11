#include <cstdio>

const int N = 5e5+5;
int n, l, r;
long long m, a[N];

bool chk(int md)
{
	long long cnt = 0;
	for(int i=1; i<=md; i++)
	{
		cnt += a[md]-a[i];
	}
	return cnt <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}
	
	l = 0, r=n+1;
	while(l+1 < r)
	{
		int mid = (l+r)>>1;
		if(chk(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	printf("%d\n", l);
	
	return 0;
}

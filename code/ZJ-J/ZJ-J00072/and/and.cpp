#include <cstdio>

constexpr int N = 2e5 + 5;

int n, m, ans, a[N];
bool vis1[N], vis2[N];

int main(void)
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		vis1[i] = true;
	}
	
	for (int k = 30; k >= 0; k--)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] & (1 << k)) vis2[i] = true;
			else vis2[i] = false;
		}
		
		int cnt = 0;
		
		for (int i = 1; i <= n; i++) if (vis1[i] && vis2[i]) cnt++;
		
		if (cnt >= m)
		{
			for (int i = 1; i <= n; i++) vis1[i] &= vis2[i];
			ans += 1 << k;
		}
	}
	
	printf("%d", ans);
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}


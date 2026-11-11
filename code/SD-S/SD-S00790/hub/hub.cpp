#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 2e6 + 55;
int c, t, n, k, u, v;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n - 1;i++) scanf("%d%d", &u, &v);
		if(c == 1)
		{
			if(k == n) printf("0\n");
			else printf("1\n");
		}
		else
		{
			if(k == n) printf("0\n");
			else
			{
				int res, m = (n-1) / 2;
				res = (m - k) / 4;
				if((m - k) % 4 != 0) res++;
				printf("%d\n", max(1, res + 1));
			}
		}
	}
	return 0;
}


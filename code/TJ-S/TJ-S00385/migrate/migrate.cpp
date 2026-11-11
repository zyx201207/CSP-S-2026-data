#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 10;

int pls[N];

int got[310][310];

inline void bfs(int x , int n , int d)
{
	memset(got , 0 , sizeof(got));
	queue <pair<int , int> > q;
	q.push(make_pair(x , 0));
	while(!q.empty())
	{
		pair <int , int> use = q.front();
		q.pop();
		for(int i = use.first + 1 ; i <= n ; i++)
		{
			if(pls[i] - pls[use.first] <= d)
			{
				q.push(make_pair(i , use.second + 1));
				got[i][use.second + 1] += 1;
			}
		}
	}
	return;
}

signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);

	int c , T;
	int n , d;
	scanf("%lld %lld" , &c , &T);
	if(c == 11 || c == 12)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &d);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &pls[i]);
			}
			if(n == 1)
			{
				printf("0\n");
				continue;
			}
			int k = 0;
			for(; ; k++)
			{
				if(k * (pls[2] - pls[1]) > d)
				{
					k--;
					break;
				}
			}
			if(k == 0 || k == 1)
			{
				printf("0\n");
			}
			else
			{
				k = (k << 1) - 1;
				printf("%lld\n" , max(n - k , 0LL));
			}
			continue;
		}
	}
	else if(c <= 6)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &d);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &pls[i]);
			}
			int ans = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				bfs(i , n , d);
				for(int j = i + 1 ; j <= n ; j++)
				{
					for(int k = 1 ; k <= n ; k++)
					{
						if(got[j][k] != 0)
						{
							if(got[j][k] == 2)
							{
								ans++;
							}
							break;
						}
					}
				}
			}
			printf("%lld\n" , ans);
		}
	}

	return 0;
}

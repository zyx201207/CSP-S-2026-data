#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100;
int c, t, n, d, x[N], pre[N], nxt[N], b[N];
const int M = 1e5 + 100;
int shun[M], ni[M];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//ERROR
	cin >> c;
	if(c == 11 or c == 12)
	{
		cin >> t;
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> x[i];
			}
			int num = 0;//how long can birds fly once
			if(n == 1)
			{
				cout << "0\n";
				continue;
			}
			num = d / (x[2] - x[1]);
			if(num == 0 or num == 1)
			{
				cout << "0\n";
			}
			else cout << max(0ll, n - num - num + 1) << "\n";
		}
	}
	else if(c == 13 or c == 14)
	{
		cin >> t;
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> x[i];
			}
			int r = 1;
			for(int l = 1; l <= n; l++)
			{
				while(r + 1 <= n and x[r + 1] - x[l] <= d)
				{
					r++;
				}
				nxt[l] = r;
			}
			int ll = n;
			for(int rr = n; rr >= 1; rr--)
			{
				while(ll - 1 >= 1 and x[rr] - x[ll - 1] <= d)
				{
					ll--;
				}
				pre[rr] = ll;
			}
	//		for(int i = 1; i <= n; i++)
	//		{
	//			printf("pre[%lld]=%lld, nxt[%lld]=%lld\n", i, pre[i], i, nxt[i]);
	//		}
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				if(nxt[i] != i)
				b[nxt[i]] = 1;
			}
			for(int i = 1; i <= n; i++)
			{
				if(pre[i] != i)
				ans += b[pre[i] + 1];
			}
			cout << ans << "\n";
		}
//		cin >> t;
//		while(t--)
//		{
//			cin >> n >> d;
//			for(int i = 1; i <= n; i++)
//			{
//				cin >> x[i];
//			}
//			int r = 1;
//			for(int l = 1; l <= n; l++)
//			{
//				while(r + 1 <= n and x[r + 1] - x[l] <= d)
//				{
//					r++;
//				}
//				nxt[l] = r;
//			}
//			int ll = n;
//			for(int rr = n; rr >= 1; rr--)
//			{
//				while(ll - 1 >= 1 and x[rr] - x[ll - 1] <= d)
//				{
//					ll--;
//				}
//				pre[rr] = ll;
//			}
//			int id = -1;
//			for(int i = 1; i <= n; i++)
//			{
//				if(pre[i] == 1 and nxt[i] == n)
//				{
//					id = i;
//				}
//			}
//			
//		}
	}
	else
	{
		//Baoli
		cin >> t;
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> x[i];
			}
			int r = 1;
			for(int l = 1; l <= n; l++)
			{
				while(r + 1 <= n and x[r + 1] - x[l] <= d)
				{
					r++;
				}
				nxt[l] = r;
			}
			int ll = n;
			for(int rr = n; rr >= 1; rr--)
			{
				while(ll - 1 >= 1 and x[rr] - x[ll - 1] <= d)
				{
					ll--;
				}
				pre[rr] = ll;
			}
	//		for(int i = 1; i <= n; i++)
	//		{
	//			printf("pre[%lld]=%lld, nxt[%lld]=%lld\n", i, pre[i], i, nxt[i]);
	//		}
			int ans = 0;
			int num = 0, tot = 0;
			for(int l = 1; l <= n; l++)
			{
				for(int r = l + 1; r <= n; r++)
				{
	//				printf("l=%lld,r=%lld\n", l, r);
					int k = l;
					num = 0;
					shun[++num] = l;
					while(nxt[k] > k and nxt[k] < r)
					{
						k = nxt[k];
						shun[++num] = k;
					}
					if(nxt[k] <= k and nxt[k] < r)
					{
						continue;
					}
					shun[++num] = r;
	//				printf("k=%lld\n", k);
					if(k - pre[r] > 1) continue;
		//			printf("1ok\n");
					int flag = k;
					k = r;
					int t = 0;
					tot = 0;
					ni[++tot] = r;
					while(pre[k] < k and pre[k] > l)
					{
						k = pre[k];
						ni[++tot] = k;
						t++;
					}
					if(pre[k] >= k and pre[k] > l)
					{
						continue;
					}
					ni[++tot] = l;
					for(int i = 1; 2 * i <= tot; i++)
					{
						swap(ni[i], ni[tot - i + 1]);
					}
					int p = 0;
					for(int i = 1; i <= num; i++)
					{
						if(shun[i] != ni[i])
						{
							p++;
							if(shun[i] - ni[i] > 1)
							{
								goto L;
							}
						}
					}
					if(p > 1)
					{
						continue;
					}
					if(nxt[l] - k > 1) continue;
	//				printf("2ok\n");
					if(nxt[l] != k and flag != pre[r] and t != 1)
					{
						continue;
					}
					if(t == 0 or flag == k)
					{
						continue;
					}
	//				printf("3ok l=%lld,r=%lld\n", l, r);
					ans++;
					L:;
				}
			}
			cout << ans << "\n";
		}
	}
}
/*
fc migrate.out migrate.ans
*/

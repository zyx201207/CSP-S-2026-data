#include<cstdio>
#include<bitset>
const int MAXN = 500010, MAXM = 300010;
int n, m, a[MAXN], c[MAXM];
int last_same[MAXM];
int ans[MAXM];
bool b[200010][3010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]), c[a[i]] ++;
	for(int i = n; i >= 1; -- i)
		if(!last_same[a[i]]) last_same[a[i]] = i;
	for(int i = n; i >= 1; -- i)
	{
		if(last_same[a[i]] == i)
		{
			for(int j = 1; j <= m; ++ j) b[i][j] = b[last_same[a[i + 1]]][j];
			b[i][a[i]] = true;
			for(int j = 1; j <= m; ++ j) ans[j] += c[a[i]] * b[i][j];
		}
	}
	for(int j = 1; j <= m; ++ j)
		printf("%d%c", ans[j], " \n"[j == m]);
	return 0;
}

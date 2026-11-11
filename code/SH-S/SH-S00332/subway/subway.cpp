#include <bits/stdc++.h>
#define MAXN 500
#define MAXM int(1e5)

int c, n, m, d, q, x, y ;
int is_psd[MAXM + 3][MAXN + 3] ;
int p[MAXM + 3] ;
int v[MAXM + 3] ;
int k[MAXN + 3] ;
int a[MAXN + 3][MAXM + 3] ;
int t[MAXN + 3][MAXM + 3] ;
int ans ;
bool is_achd[MAXN + 3] ;
bool vst[MAXM + 3] ;
void dfs(int s, int nt, int l) //地点、时间、线路 
{
//	printf("S={%d}", s) ;
	//从s号点开始沿着l线搜索 
	for (int i = 1; i <= k[l]; i++)
	{
//		printf("a[l][i]=[%d]", a[l][i]) ; 
		if (a[l][i] == s)
		{
//			printf(" YEAH") ;
			nt += t[l][i] ;//入站时间 
			break ;
		}
	}
	vst[s] = true ;//标记 
	
	if (is_achd[l])
	{
		for (int i = 1; i <= k[l]; i++)
		{
			if (a[l][i] == y)
			{
//				printf(" NAH") ;
				nt += t[l][i] ;
				break ;
			}
		}
		ans = std::min(ans, nt) ;
//		printf("[%d]", nt) ;
		vst[s] = false ;
//		printf("%d", ans) ;
//		exit(0) ;
		return ;
	}
	for (int i = 1; i <= k[l]; i++) //枚举l上的点 
	{
		for (int j = 1; j <= p[a[l][i]]; j++) // 枚举当前点换乘线路 
		{
			if (!vst[a[l][i]] && (is_psd[a[l][i]][j] != l))
			{
				dfs(a[l][i], nt + t[l][i], is_psd[a[l][i]][j]) ;
			}
		}
	}
	vst[s] = false ;
	return ;
}
int main()
{
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q) ;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &v[i]) ;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]) ;
		for (int j = 1; j <= k[i]; j++)
		{
			scanf("%d %d", &a[i][j], &t[i][j]) ;
			is_psd[a[i][j]][++p[a[i][j]]] = i ;
		}
	}
	while (q--)
	{
		memset(is_achd, false, sizeof is_achd) ;
		ans = 2147483647 ;
		scanf("%d %d", &x, &y) ;
		for (int i = 1; i <= p[y]; i++)
		{
			is_achd[is_psd[y][i]] = true ;
		}
		for (int i = 1; i <= p[x]; i++)
		{
//			printf("T%d_%d ", i,is_psd[x][i]) ;
			dfs(x, 0, is_psd[x][i]) ;
		}
		printf("%d\n", ans + v[x] + v[y]) ;
	}
	return 0 ;
}

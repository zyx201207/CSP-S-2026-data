#include <cstdio>

constexpr int N = 5e5 + 5, M = 3e5 + 5;

int n, m, idx, a[N], t[N], ans[M], lst[M];

int main(void)
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) t[j] = 0;
		for (int j = 1; j <= m; j++) lst[j] = 0;
		
		idx = i;
		
		for (int j = i; j <= n; j++)
		{
			t[idx++] = a[j];
			
			if (lst[a[j]])
			{
				int temp = lst[a[j]];
				while (idx > temp) lst[t[idx--]] = 0;
				
				t[idx++] = a[j];
				lst[a[j]] = idx - 1;
			}
			else lst[a[j]] = idx - 1;
		}
		
		for (int j = i; j <= idx - 1; j++) ans[t[j]]++;
	}
	
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

// 11:10
// kan lai mei you shi jian xie xiao zuo wen le
// xi wang neng bei shou lu
// CSP-S 1= pls
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
// freopen // freopen // freopen // freopen // freopen // freopen // freopen // freopen // freopen // freopen
// 11:40
// ji xian! zong suan tiao chu lai le
// 100 + 100 + 100 + 24 = 324
// 11:46
// ? zen me guo bu liao card3
// suan le tiao ni ma 300 ye ke yi le
// rp++ fan zheng shi guo lai wan yi tang... (9 yue fen que zhen zhong du yi yu le, gen ben mei fa shen du si kao
// zai jian la da jia
// guan zhu luo gu 998662 xie xie, wawa


#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int cards[N];
int ncards[N], findcard[M], idx; // 第一次出现的地方 
int ans[M];

int main()
{
	// system("fc card.out card4.ans");
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) scanf("%d", &cards[i]);
	for(int i = 1; i <= n; i ++) // 进行的轮数
	{
		idx = 0;
		for(int j = 1; j <= m; j ++) findcard[j] = -1;
		for(int j = i; j <= n; j ++) // 取的牌 
		{
			if(findcard[cards[j]] == -1) findcard[cards[j]] = idx + 1;
			else
			{
				for(int k = findcard[cards[j]] + 1; k <= idx; k ++) findcard[ncards[k]] = -1;
				continue;
			}
			idx ++;
			ncards[idx] = cards[j];
		} 
		for(int i = 1; i <= m; i ++) ans[i] += (findcard[i] != -1);
	}
	for(int i = 1; i <= m; i ++) printf("%d ", ans[i]);
	puts("");
	return 0;
}

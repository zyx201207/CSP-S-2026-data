#include <bits/stdc++.h>
using namespace std;
int z[500005], top; //栈
int nu[500005];//数字
bool nuz[300005];//数字占用
int ans[300005];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nu[i]);
//	long long sum=0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			//	printf("nu[%d]入栈\n", j);
			//入栈 nu[j]为当前入栈
			if (nuz[nu[j]] == 1) { /*当前入栈数字占用？*/
				for (int k = 1; k <= top; k++)
					if (z[k] == nu[j]) { //找到
						top = k;
						//		printf("占用 top=%d\n", k);
					}
			} else {
				z[++top] = nu[j], nuz[nu[j]] = 1; //入栈，占用
				//	printf("%d入栈 top:%d\n", nu[j], top);
				//	printf("zai栈：");
				//	for (int j = 1; j <= top; j++)
				//		printf("%d ", z[j]);
				//	printf("\n");
			}
		}
//		if(nuz[i]==1)
//			sum++;
		//	printf("栈：");
		//	for (int j = 1; j <= top; j++)
		//		printf("%d ", z[j]);
		//	printf("\n");
		//	printf("top:%d\n", top);
		for (int j = 1; j <= top; j++)
			ans[z[j]]++;//增加答案
		memset(nuz, 0, sizeof(nuz));
		top = 0; //清除栈 清除占用
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", ans[i]);
	}
}
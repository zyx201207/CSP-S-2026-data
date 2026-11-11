#include<bits/stdc++.h>
using namespace std;

int n, m, a[500010], ans[300010];
int card[500010], ape[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	
	for (int i = 1;i <= n;i++) {
		int r = 0;
		memset(ape, 0, sizeof(ape));
		
		for (int j = i;j <= n;j++) {
			card[++r] = a[j];
			
			if (ape[a[j]]) {
				do {r--;}
				while(card[r] != a[j]);
			} else {
				ape[a[j]] = 1;
			}
		}
		
		for (int i = 1;i <= r;i++)
			ans[card[i]]++;
	}
	
	for (int i = 1;i <= m;i++)
		printf("%d ", ans[i]);
	return 0;
}

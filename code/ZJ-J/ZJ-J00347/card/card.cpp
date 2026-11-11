#include<bits/stdc++.h>
using namespace std;
queue <int> q;
int n, m, st, a[500010], have[300010], c[300010];
bool could[300010];
//记得去注释！！
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i<=n; ++i){
		scanf("%d", a+i);
	}
	for (int i = 1; i<=n; ++i){//No.n game
		memset(have, 0, sizeof(have));
		memset(could, false, sizeof(could));
		st = i;
		for (int j = st; j<=n; ++j){
			if (have[a[j]] != 0){
				st = j; 
				
			}
			
			have[a[j]] = j;
		}
		for (int j = st; j<=n; ++j){
			if (could[a[j]] == false){
				c[a[j]]++;
				could[a[j]] = true;
			}
		}
	}
	for (int i = 1; i<=m; ++i){
		printf("%d ", c[i]);
	}
	return 0;
}

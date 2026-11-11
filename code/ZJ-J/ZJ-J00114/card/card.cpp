#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;

int n, m, a[N];
int vis[M], f[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int k = 1; k <= n; k++){
		memset(vis, 0, sizeof(vis));
		for(int i = k; i <= n; i++){
			if(vis[a[i]] != 0){
				for(int j = vis[a[i]]; j <= i - 1; j++){
					vis[a[j]] = 0;
				}
			}
			vis[a[i]] = i;
		}
		for(int i = 1; i <= m; i++) if(vis[i] != 0) f[i]++;
	}
	for(int i = 1; i <= m; i++) printf("%d ", f[i]);
	return 0;
}
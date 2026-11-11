#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k, t[505][500005], ans[505];
vector<int> sub[505];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int j = 1; j <= n; j++){
		scanf("%d", &k);
		for(int i = 1; i <= k; i++){
			int a;
			scanf("%d %d", &a, &t[j][i]);
			sub[j].push_back(a);
		}
	}
	while(q--){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int i = 1; i <= n; i++){
			for(int j = x + 1; j <= d; j++){
				if(sub[i][j] == x){
					ans[i] += w[y] + t[i - 1][y] + w[x] + t[i - 1][x];
					printf("%d %d %d %d %d %d\n",w[x],i,x,w[y],i,y);
				}
			}	
		}
		int minn = 2e9;
		for(int i = 1; i <= n; i++){
			if(ans[i] == 0) continue;
			minn = min(minn, ans[i]);
		}
		printf("%d", minn);
	}
	return 0;
} 


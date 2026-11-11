#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

#define int long long

int n, m, a[500005], ans[500005], vis[500005], viss[500005], nxt[500005];

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	for(int i = n;i >= 1;i--){
		if(!viss[a[i]])
			viss[a[i]] = i;
		nxt[i] = viss[a[i]];
	}
	for(int l = 1;l <= n;l++){
		for(int i = l;i <= n;i++){
			if(nxt[i] != 0)
				i = nxt[i];
			ans[a[i]]++;
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%lld ", ans[i]);
	return 0;
}
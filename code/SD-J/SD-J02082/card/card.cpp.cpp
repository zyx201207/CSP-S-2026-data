#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
int main(){
	freopen("card.in", "r",stdin);
	freopen("card.out", "w",stdout);
	cin >>n >>m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int c[500005] = {0}, p = n-i+1;
		int q = 0, k = i;
		while(p){
			for (int j = 1; j <= q; j++){
				if (c[j] == a[k]){
					for (int d = j; d <= q; d++){
						c[d] = 0;
						p--;
						q--;
					} 
				}
			}
			c[q] = a[k];
			q++;
		}
		for (int j = 0; j <= q; j++) {
			ans[a[j]]++;
		}
	}
	for (int i = 0; i <= m; i++){
		cout << ans[i];
	}
	return 0;
}


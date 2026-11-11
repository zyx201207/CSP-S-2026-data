#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;int t;t = n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (t--){
		for (int i = n - t + 1;i <= n;i++) {
			c[i] = a[i];
		}
		for (int i = n - t + 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				if (c[i] == -1) break;
				if (c[j] == -1) continue;
				if (c[i] == c[j]){
					for (int z = i;z <= j - 1;z++) {
						c[z] = -1;
					}
				}
			}
		}
		for (int i = n - t + 1;i <= n;i++){
			if (c[i] != -1){
				b[c[i]]++;	
			}
		}	
	}
	for (int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}

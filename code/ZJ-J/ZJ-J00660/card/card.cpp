#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, a[N];
int b[N], ans[N], f[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int d = 0;
		for(int j = i; j <= n; j++){
			if(f[a[j]]){
				for(int k = d; k >= 1; k--){
					if(b[k] == a[j]){
						d = k; break;
					}
					f[b[k]] = 0;
				}
			}else{
				b[++d] = a[j]; f[a[j]] = 1;
			}
		}
		for(int j = 1; j <= d; j++){
			ans[b[j]]++;
		}
		memset(f, 0, sizeof(f));
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
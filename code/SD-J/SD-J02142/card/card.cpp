#include <bits/stdc++.h>
using namespace std;
long long n, m, a[555555], b[555555], c[333333];
int main(){
	freopen("card.in", "r" , stdin);
	freopen("card.out", "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			b[i] = 0;
		}
		int z = i, zzz = 1;
		for(int j = i; j <= n; j++){
			for(int k = n; k >= j; k--){
				if(a[k] == a[j]){
					z = k;
					break;
				}
			}
			b[zzz++] = a[z++];
			j = z - 1;
		}
		for(int j = 1; j < zzz; j++){
			c[b[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << c[i] << " ";
	}
	return 0;
}

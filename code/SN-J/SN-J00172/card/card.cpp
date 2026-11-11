#include <bits/stdc++.h>
using namespace std;
int n, m, sum, p[500005], z[500005], w[300005], cnt[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> p[i];
	}
	for(int i = 1;i <= n;i++){
		for(int l = 1;l <= n;l++){
			z[l] = 0;
			w[l]= 0;
		}
		sum = 1;
		for(int j = i;j <= n;j++){
			z[sum] = p[j];
			if(w[p[j]] != 0){
				for(int f = w[p[j]];f < sum;f++){
					z[f] = 0;
				}
				sum = w[p[j]];
				z[sum] = p[j];
			}else{
				w[p[j]] = sum;
			}
			sum++;
		}
		for(int k = 1;k < sum;k++){
			cnt[z[k]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}

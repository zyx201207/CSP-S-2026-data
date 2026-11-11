#include <bits/stdc++.h>
using namespace std;
long long n, m, a[300005], b[300005], card[300005], sum[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){ 
		cin >> a[i];
		
	}
	for(int i= 1; i <= n;i++){
		for(int j = i; j <= n;j++){
			if(b[a[j]] == 0){
				b[a[j]] = 1;
				card[j] = a[j];
			}
			else {
				for(int k = i; k < j; k++) card[k] = -1;
				card[j] = a[j];
				for(int k = 1 ; k <= m ; k ++) b[k] = 0;
				b[a[j]] = 1;
			}
		}
		for(int j = i; j <= n; j++){
			if(card[j] != -1) sum[card[j]]++;
		}
		for(int j = 1; j <= m; j++){ 
			b[j] = 0;
			card[j] = 0;
		}
	}
	for(int i = 1; i <= m; i++) cout << sum[i] << " ";
	return 0;
} 

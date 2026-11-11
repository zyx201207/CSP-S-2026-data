#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], m, maxn = -100000, b[500005], cnt = 0;
int main(){
	
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long tm = m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n);
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			b[j] = a[j];
		}
		for(int j = i; j >= 1; j--){
			if(a[j] == a[i]){
				cnt++;
				continue;
			}
			if(b[j] < a[i]){
				tm -= a[i] - b[j];
				if(tm < 0) break;
				if(tm >= 0) cnt++;
			}
			if(tm <= 0) break;
		}
		maxn = max(maxn, cnt);
		cnt = 0;
		tm = m;
	}
	cout << maxn;
	return 0;
}

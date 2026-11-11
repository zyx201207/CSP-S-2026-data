#include<bits/stdc++.h>
using namespace std;
long long k = 1, ans, n, m;
vector<long long> a;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= 32; i++){
		k *= 2;
	}
	while(k /= 2){
		int sum = 0;
		for(int i = 0; i < a.size(); i++){
			if(k <= a[i]){
				sum++;
			}
		}
		if(sum >= m){
			for(int i = 0; i < a.size(); i++){
				if(a[i] < k){
					a[i] = 0;
				} else{
					a[i] %= k;
				}
			}
			ans += k;
		} else{
			for(int i = 0; i < a.size(); i++){
				a[i] %= k;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 

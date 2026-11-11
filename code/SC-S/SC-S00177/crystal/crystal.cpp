#include<bits/stdc++.h>
using namespace std;
int n;
long long m, sum = 0, num, ans = 0;
long long a[500010];
int main(){
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	num = round(1.0 * sum / n);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i + 1]){
			continue;
		}
		if(a[i] >= num){
			for(int j = i; j >= 1; j--){
				while(a[j] < num){
					a[j]++;
					m--;
				}
				if(m >= 0){
					ans++;
				}else{
					break;
				}
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
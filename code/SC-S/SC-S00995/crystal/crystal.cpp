#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], t, sum, b[500010], ans, m1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		sum = 0;
		for(int j = 1; j <= i; j++){
			b[j] = (a[i] - a[j]);
			//cout << b[j] << ' ';
		}
		//cout << '\n';
		m1 = m;
		for(int j = i; j >= 1; j--){
			if(m1 - b[j] >= 0){
				m1 -= b[j];
				sum++;
			}else{
				break;
			}
		}
		ans = max(sum, ans);
	}
	cout << ans << '\n';
	return 0;
}
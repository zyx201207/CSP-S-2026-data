#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], ans, tmp, cnt;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		tmp = m, cnt = 1;
		for(int j = i - 1; j >= 1; j--){
			if(tmp - (a[i] - a[j]) >= 0){
				cnt++;
				tmp -= (a[i] - a[j]);
			}else{
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int a[N];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >>n >>m;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];
	}
	if(m == 2){
		long long ans = 0;
		for(int i = 1; i <= n ;i++){
			for(int j = i + 1; j <= n; j++){
				long long k = a[i] & a[j];
				ans = max(k , ans);
			}
		}
		cout <<ans;
	}
	if(m == 1){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans , a[i]);
		}
		cout << ans;
		return 0;
	}
	int ans = a[1];
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1; i <= m; i++){
		ans = ans & a[i];
	}
	cout << ans;

	return 0;
}


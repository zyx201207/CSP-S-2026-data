#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10;

long long n , m , a[N] , ans;

bool check(){
	for(long long i = 2 ; i <= n ; i++)
		if(a[i] - a[i-1] != a[2] - a[1])
			return false;
	return true;
}

int main(){

	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	if(n <= 5000){
		for(long long i = 1 ; i <= n ; i++){
			long long tmp = a[i] , mm = m , lst;
			for(long long j = i ; j >= 1 ; j--){
				if(mm - (tmp - a[j]) >= 0){
					mm -= (tmp - a[j]);
					lst = j;
				}
				else
					break;
			}
			ans = max(ans , i - lst + 1);
		}
		cout << ans << endl;
	}else if(check()){
		long long d = a[2] - a[1] , cnt = 1;
		for(long long i = 1 ; i <= n ; i++){
			if(m - i * d >= 0){
				m -= i * d;
				cnt++;
			}
			else
				break;
		}
		cout << cnt << endl;
	}
	
	return 0;
}
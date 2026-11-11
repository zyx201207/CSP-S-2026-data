#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , ans;
long long sum[N];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		int l = 1 , r = i , mid , flag;
		while(l <= r){
			mid = (l + r) / 2;
			long long val = 1ll * a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
			if(val <= m){
				flag = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		ans = max(ans , i - flag + 1);
	}
	cout << ans;
	return 0;
}

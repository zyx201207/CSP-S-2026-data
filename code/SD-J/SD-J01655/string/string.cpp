#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n ; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	long long mid = (sum+1) / 2;
	long long need;
	if(mid % 2 == 0){
		need = mid;
	}else{
		need = mid - 1;
	}
	long long ans = 0;
	int l = 1,r = n;
	while(need > 0 && l <= r){
		if(c[l] == c[r]){
			if(need <= 0){
				cout << ans;
				return 0;
			}
			if(a[l] > a[r]){
				need -= min(a[l],a[r]);
				a[l] -= a[r];
				r--;
			}else if(a[l] < a[r]){
				need -= a[l];
				a[r] -= a[l];
				l++;
			}else{
				need -= a[l];
				l++;
				r--;
			}
		}else{
			if(need < min(a[l],a[r])){
				ans += need;
				cout << ans;
				return 0;
			}else if(a[l] > a[r]){
				a[l] -= a[r];
				ans += a[r];
				need -= a[r];
				r--;
			}else if(a[l] < a[r]){
				a[r] -= a[l];
				ans += a[l];
				need -= a[l];
				l++;
			}else{
				ans += a[l];
				need -= a[l];
				r--;
				l++;
			}
		}
	}
	cout << ans;
	return 0;
} 

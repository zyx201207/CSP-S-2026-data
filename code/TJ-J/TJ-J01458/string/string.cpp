#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
ll a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	ll ans = 0;
	while(l <= r){
		if(c[l] == c[r]){
			if(a[l] == a[r]){
				l ++, r --;
			}else if(a[l] < a[r]){
				a[r] -= a[l];
				l ++;
			}else{
				a[l] -= a[r];
				r --;
			}
		}else{
			if(a[l] == a[r]){
				ans += a[l];
				l ++, r --;
			}else if(a[l] < a[r]){
				ans += a[l];
				a[r] -= a[l];
				l ++;
			}else{
				ans += a[r];
				a[l] -= a[r];
				r --;
			}
		}
	}
	cout << ans;
	return 0;
}


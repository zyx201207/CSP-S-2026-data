#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N],sum[N];
bool check(int x){
	for(int i = x;i <= n;i++){
		int f = i - x + 1;
		ll s = sum[i] - sum[f - 1];
		if(s + m >= x * a[i]) return 1; 
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	ll l = 1,r = n,ans = 0;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else
			r = mid - 1;
	}
	cout << ans;
	return 0;
} 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
char c[200010];
ll s[200010];
ll s1[200010];
ll sum;
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
		sum += a[i];
		s[i] = s[i-1] + a[i];
	}
	for(int i = n;i>=1;i--){
		s1[i] = s1[i+1] + a[i];
	}
	ll li = 0;
	ll l = 0;
	ll ri = n;
	ll r = 0;
	for(int i = 1;i<=n;i++){
		if(l>=sum/2)break;
		l += a[i];
		while(a[i]>a[ri]){
			a[i] -= a[ri];
			
			if(c[i] != c[ri])
			ans += a[ri];
			ri --;
		}
		if(c[i] != c[ri])
			ans += a[i];
		a[ri] -= a[i];
	}
	cout << ans;
	return 0;
}
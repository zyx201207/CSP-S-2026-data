#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
ll n, a[N], ans = 0, alen = 0, l, r;
char c[N];
int main(){
	//freopen("string.in", "-r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		alen++;
		cin>>a[alen]>>c[alen];
		if(i==1){
			continue;
		}
		if(c[alen] == c[alen-1]){
			a[alen-1] += a[alen];
			alen--;
		}
	}
	ll l = 1, r = alen;
	while(l<=r){
		if(c[l] == c[r]){
			if(a[l] < a[r]){
				l++;
				a[r] -= a[l-1];
			}else{
				r--;
				a[l] -= a[r+1];
			}
		}else{
			if(a[l] < a[r]){
				ans += a[l];
				a[r] -= a[l];
				l++;
			}else{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

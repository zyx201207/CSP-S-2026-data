#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 50;
ll n,m,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans = 0;
	ll l = 0,r = n-1;
	for(int i = n-1; i>=0; i--){
		ll sum = 0,mx = 0;
		for(ll j = i; j>=0; j--){
			sum += (a[i] - a[j]);
			if(m >= sum){
				mx++;
			}else{
				break;
			}
		}
		ans = max(ans,mx);
	}
	cout<<ans<<endl;
	return 0;
} 
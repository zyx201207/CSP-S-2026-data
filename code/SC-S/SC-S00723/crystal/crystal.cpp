#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,use=0;
	for(ll i=1;i<=n;i++){
		use += (i-l)*(a[i]-a[i-1]);
		while(use>m){
			use -= (a[i]-a[i-1]);
			l++;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
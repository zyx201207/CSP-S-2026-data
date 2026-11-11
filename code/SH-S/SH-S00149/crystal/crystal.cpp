#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx = 0,n,m,a[514514],s[514514];
ll cal(ll x){
	ll l = 0,r = x-1,ans = 0;
	while(l <= r){
		ll mid = (l + r)/2;
		if(mid * a[x] - (s[x-1]-s[x-1-mid]) <= m){
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i = 1;i <= n;i++) s[i] = s[i-1] + a[i];	
	for(ll i = 1;i <= n;i++) mx = max(mx,cal(i)+1);
	cout<<mx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

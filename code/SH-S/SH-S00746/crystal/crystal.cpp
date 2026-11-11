#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+9;
ll n,ans,l = 1,r = 1,sum,m,a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);a[0] = -2e18;
	for (ll i = 1;i <= n;i++) d[i] = a[i] - a[i-1];
	while (l <= n){
		//cout<<l<<' '<<r<<' '<<sum<<' '<<endl;
		if (sum <= m){
			ans = max(ans,r-l+1);
			if (r < n){
				r++;
				sum += d[r] * (r-l);
			}else{
				l++;
				sum -= a[r] - a[l-1];
			}
		}else{
			l++;
			sum -= a[r] - a[l-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 500500;
ll a[maxn],sum[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,i,j;
	cin>>n>>m;
	for(i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	ll ans = 0;
	for(i = 1;i <= n;i++){
		ll l = 1,r = i,flag = 0,mid;
		while(l <= r){
			mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m){
				flag = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		if(flag) ans = max(ans,i - flag + 1);
	}
	cout<<ans;
	return 0;
}

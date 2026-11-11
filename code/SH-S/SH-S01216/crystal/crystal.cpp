#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500010],sum[500010],ans;
ll search(ll mb,ll i){
	ll l=1,r=i;
	while (l<r){
		ll mid=(l+r)/2;
		if (mb-sum[i]-(mid-1)*a[i]+sum[mid-1]<=m){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return i-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)  sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		ll mb=a[i]*i;
		ans=max(ans,search(mb,i));
	}
	cout<<ans;
	return 0;
}

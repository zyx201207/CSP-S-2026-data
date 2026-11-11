#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+5;
ll n,m,a[MAXN],sum[MAXN],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,re=i;
		while(l<=r){
			ll mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				re=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-re+1);
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,a[N],m,b[N],sum[N],num;
bool check(int x){
	ll ans=1e9;
	for(int i=x;i<=n;i++)ans=min(ans,sum[i]-sum[i-x]-(a[n]-a[i])*x);
	return ans<=m;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,mid;
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
		sum[i]=sum[i-1]+b[i];
	}
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			num=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<num;
	return 0;
} 
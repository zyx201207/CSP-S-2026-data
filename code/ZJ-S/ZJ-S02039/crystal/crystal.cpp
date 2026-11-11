#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;
inline void init(){
}
ll a[N],sum[N];
signed main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int maxn=1;
	for(int i=n;i>=maxn;i--){
		ll step=a[i];
		int l=1,r=i,mid=(l+r)>>1;
		while(l<=r){
			mid=(l+r)>>1;
			if(m+sum[i]-sum[mid-1]<1ll*step*(i-mid+1))l=mid+1;
			else r=mid-1;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}

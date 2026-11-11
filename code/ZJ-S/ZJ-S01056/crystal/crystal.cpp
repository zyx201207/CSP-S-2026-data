#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		// erfen
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1ll;
			if(a[i]*(i-mid+1ll)-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1ll);
	}
	cout<<ans;
	return 0;
}
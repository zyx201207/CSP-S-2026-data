#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
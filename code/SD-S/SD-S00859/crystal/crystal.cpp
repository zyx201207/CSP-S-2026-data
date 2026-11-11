#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i,anss=0;
		while (l<=r){
			int mid=(l+r)>>1;
			if (a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				anss=max(anss,i-mid+1);
				r=mid-1; 
			}else l=mid+1;
		}ans=max(ans,anss);
	}cout<<ans;
}//ÖØ¹¹+1 

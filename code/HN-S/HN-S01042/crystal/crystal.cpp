#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],s[1000005],ans=1,l,r,mid;
signed main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		l=0,r=i;
		while(l+1<r){
			mid=l+(r-l)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}

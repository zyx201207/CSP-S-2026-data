#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
int n,m,a[510000],s[510000],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ret=0;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m)r=mid-1,ret=mid;
			else l=mid+1;
		}
		ans=max(ans,i-ret+1);
	}
	cout<<ans;
	return 0;
}

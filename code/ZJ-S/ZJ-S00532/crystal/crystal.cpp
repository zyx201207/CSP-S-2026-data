#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],d[N],sum[N],ans=0,n,m,i;
bool check(int mid){
	int k=i-mid+1;
	if(k*a[i]<=m+sum[i]-sum[mid-1])return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++){
		int l=1,r=i,mid=(l+r)>>1,ans1=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans1=mid;//use i-mid
			else l=mid+1;
		}
		ans=max(ans,i-ans1+1);
	}
	cout<<ans;
	return 0;
}
//start 0h
//end 1h

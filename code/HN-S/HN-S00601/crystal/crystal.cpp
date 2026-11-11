#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		int l=0,r=i,mid=(l+r)>>1;
		while(l<=r){
			mid=(l+r)>>1;
			if(sum[i]-sum[mid]<=m)ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
	
}

#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
long long a[N],sum[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if(1ll*a[i]*(i-mid+1)+sum[mid-1]<=m+sum[i])r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
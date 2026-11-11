#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=0;
	for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(long long i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j]==a[j+1])j++;
		long long l=1,r=i-1,p=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,j-p+1);
		i=j;
	}
	cout<<ans;
	return 0;
}

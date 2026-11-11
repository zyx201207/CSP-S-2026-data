#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,ma,a[500010],b[500010],sum[500010],sum2[500010];
int ef(int x){
	int t,w,ans=x+1;
	t=1;w=x;
	while(t<=w){
		int mid=(t+w)/2;
		if(sum[x]-sum[mid-1]-(mid-1)*(sum2[x]-sum2[mid-1])<=m)ans=mid,w=mid-1;
		else t=mid+1;
	}
	return x-ans+2;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
		b[i]=a[i+1]-a[i],sum[i]=sum[i-1]+i*b[i],sum2[i]=sum2[i-1]+b[i];
	for(i=1;i<n;i++){
		ma=max(ma,ef(i));
	}
	cout<<ma;
	return 0;
}
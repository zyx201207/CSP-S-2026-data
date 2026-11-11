#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],ans[500005],n,m;
long long fd(int x){
	long long l=1,r=x;
	while(l<=r){
		long long mid=(l+r)/2,p=x-mid;
		if( (p*a[x]-(sum[x-1]-sum[mid-1])) < m)r=mid-1;
		else if( (p*a[x]-(sum[x-1]-sum[mid-1])) > m)l=mid+1;
		else return mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){ 
		for(int i=1;i<=n;i++){
			long long rst=0;bool flag=0;
			for(int j=i-1;j>=1;j--){
				rst+=(a[i]-a[j]);
				if(rst>m){
					rst-=(a[i]-a[j]);
					ans[i]=(i-j);
					flag=1;
					break;
				} 
			}
			if(flag==0)ans[i]=i;
		}
		long long s=-1e18;
		for(int i=1;i<=n;i++)s=max(s,ans[i]);
		cout<<s; 
	}
	else{
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(int t=1;t<=n;t++)ans[t]=t-fd(t)+1;
		long long rst=-1e18;
		for(int i=1;i<=n;i++)rst=max(rst,ans[i]);
		cout<<rst;
	}
	return 0;
} 

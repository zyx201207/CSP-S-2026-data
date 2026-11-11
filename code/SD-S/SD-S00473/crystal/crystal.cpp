#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=1;
	cin>>n>>m;
	long long a[n+5]={0},sum[n+5]={0},d[n+5]={0};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
		sum[i]=(i-1)*a[i]-d[i-1];
	}
	if(m>=sum[n]){
		cout<<n;
		return 0; 
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		long long ans=1e18;
		long long x=sum[i];
		while(l<=r){
			long long mid=(l+r)>>1;
			long long ne=x-(mid-1)*a[i]+d[mid-1];
			if(ne>m){
				l=mid+1;
			}else{
				ans=mid;
				r=mid-1;
			}
		}
		if(ans!=1e18){
			maxx=max(maxx,i-ans+1);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],b[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long mx=-10000000000001,mn=10000000000005,be=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		if(a[i]>mx)
			mx=a[i];
		if(a[i]<mn)
			mn=a[i];
	}
	sort(a+1,a+n+1);
	if(n>=2000){
		for(long long i=a[n/2-900];i<=a[n/2+900];i++){
			long long ans=m,cnt=0;
			for(long long j=n;j>=1;j--){
				if(a[j]>i)
					continue;
				else{
					if(ans>=i-a[j]){
						cnt++;ans-=(i-a[j]);
					}else 
						break;
				}
			}
		if(be<cnt)
			be=cnt;
		}
	}
	else{
		for(long long i=mn;i<=mx;i++){
			long long ans=m,cnt=0;
			for(long long j=n;j>=1;j--){
				if(a[j]>i)
					continue;
				else{
					if(ans>=i-a[j]){
						cnt++;ans-=(i-a[j]);
					}else{
						break;
					}
				}
			}
			if(be<cnt)
				be=cnt;
		}
	cout<<be;
	return 0;
	}
}
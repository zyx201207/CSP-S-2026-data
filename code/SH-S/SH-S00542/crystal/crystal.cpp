#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k;
long long a[500005],cf[500005],sum[500005],sum2[500005];
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+cf[i];
		sum2[i]=sum2[i-1]+sum[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int x=ans;x+i<=n;x++){
			if(1ll*x*sum[i+x]-(sum2[i+x-1]-sum2[i-1])<=m){
				ans=max(ans,x);
			}
			else break;
		}
	}
	cout<<ans+1;
	return 0; 
}

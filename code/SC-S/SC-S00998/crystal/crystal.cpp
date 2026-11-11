#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m); 	
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i]-a[i-1];
	int i=0,j=1;long long cost=0;
	while(i<=n){
		i++;cost+=(sum[i]-sum[i-1])*(i-j);
		while(j<=i&&cost>m){j++,cost-=sum[i]-sum[j];}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
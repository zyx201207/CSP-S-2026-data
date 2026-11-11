#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=1;
	while(r<=n){
		while(l<r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m){
			l++;
		}
		ans=max(r-l+1,ans);
		r++;
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans,sum;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	for(int l=1,r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	
	return 0;
}

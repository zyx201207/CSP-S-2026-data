#include<bits/stdc++.h>
using namespace std;
int ans,n;
long long m,sum[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)ans=max(ans,i-mid+1),r=mid-1;else
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
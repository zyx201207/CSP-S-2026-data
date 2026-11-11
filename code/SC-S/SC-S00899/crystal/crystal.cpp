#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],head,ans,sum,f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		f[i]=b[i]+f[i-1];
	}
	head=1;
	for(int i=2;i<=n;i++){
		sum+=(i-head)*(b[i]);
		while(sum>m){
			head++;
			sum-=f[i]-f[head];
		}
		ans=max(i-head+1,ans);
	}
	printf("%lld",ans);
	return 0;
}
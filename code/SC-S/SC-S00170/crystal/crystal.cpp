#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n,m,a[N],sum[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int l=0,r=1;r<=n;r++){
		while((r-l)*a[r]-sum[r]+sum[l]>m)
			++l;
		ans=max(ans,r-l);
	}
	printf("%d\n",ans);
}
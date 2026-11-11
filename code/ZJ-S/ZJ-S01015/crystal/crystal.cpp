#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500010],b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long num=0,ans=0,l=1,r=0;
	while(r<n){
		r++;
		num=num+(r-l)*b[r];
		while(!(num<=m) && l<=r){
			num=num-(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}

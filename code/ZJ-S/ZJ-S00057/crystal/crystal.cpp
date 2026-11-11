#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	    s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		long long l=0,r=i;
		while(l+1<r){
			long long mm=(l+r)/2;
			if(1LL*a[i]*(i-mm)-s[i-1]+s[mm-1]<=m)
				r=mm;
			else
				l=mm;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld",ans);
	return 0;
}

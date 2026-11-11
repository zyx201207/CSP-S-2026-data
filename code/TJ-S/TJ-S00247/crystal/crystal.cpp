#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,l,r,md;
long long a[500005],s[500005];
int main(){
	//mol Gzy mol wb
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(long long i=n;i>=1;i--){
		if(i<=ans)
			break;
		l=1;
		r=i;
		md=(l+r)/2;
		while(1){
			if(l>r||l>i||r>i||md>i)
				break;
			if((s[i]-s[md-1]+m)>((i-md+1)*a[i])){
				if(ans<(i-md+1))
					ans=i-md+1;
				r=md-1;
				md=(l+r)/2;
				continue;
			}
			if((s[i]-s[md-1]+m)<((i-md+1)*a[i])){
				l=md+1;
				md=(l+r)/2;
				continue;
			}	
			if((s[i]-s[md-1]+m)==((i-md+1)*a[i])){
				if(ans<(i-md+1))
					ans=i-md+1;
				break;
			}	
		}
	}
	printf("%lld",ans);
	return 0;
}

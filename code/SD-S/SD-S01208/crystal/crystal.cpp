#include<bits/stdc++.h>
using namespace std;
long long a[500009];
long long f[500009];
int main(){
//	freopen("crystal3.in","r",stdin);
//	freopen("hywhywhywhywh.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
//		printf("%lld ",f[i]);
	}
//	printf("\n");
	long long l=0,ans=0;
	for(long long i=1;i<=n;i++){
		while(l<i&&a[i]*(i-l)-(f[i]-f[l])>m){
			l++;
		}
		ans=max(ans,i-l);
//		printf("%lld ",l);
	}
//	printf("\n");
	printf("%lld\n",ans);
	return 0;
}


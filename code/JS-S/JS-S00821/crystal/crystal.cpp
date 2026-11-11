#include<stdio.h>
#include<algorithm>
#define M 500005
using namespace std;
using ll=long long;
int n;
ll m,a[M],s[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;++i){
		while(j<=i&&a[i]*(i-j+1)-s[i]+s[j-1]>m) ++j;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
}
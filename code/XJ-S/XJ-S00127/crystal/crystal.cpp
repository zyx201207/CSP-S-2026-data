#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m,a[500005],sum[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	
	int j=1;
	int ans=1;
	for(int i=1;i<=n;++i){
		while(j<i && a[i]*(i-j+1)-(sum[i]-sum[j-1]) > m) ++j;
		ans = max(ans, i-j+1);
	}
	printf("%d\n",ans);
	
	return 0;
}

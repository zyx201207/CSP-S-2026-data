#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int b[500005];
int c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=2) b[i]=a[i]-a[i-1];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(i-1)*b[i];
		if(c[i]<=m) ans=i;
	}
	printf("%lld",ans);
	return 0;
}

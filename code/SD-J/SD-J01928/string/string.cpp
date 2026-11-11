#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
long long n, m;
long long a[N];
char c[N];
long long ans, l, r, now;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	l=1, r=n;
	while(l<r){
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		now=min(a[l],a[r]);
		a[l]-=now;
		a[r]-=now;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--; 
	}
	printf("%lld",ans);
	return 0;
}

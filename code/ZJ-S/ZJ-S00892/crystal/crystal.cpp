#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n;
long long m;
long long a[maxn];
int ans=0;
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=0;
	long long cnt=0;
	while(r<n){
		r++;
		cnt=cnt+1ll*(r-l)*(a[r]-a[r-1]);
		while(l<r&&cnt>m) cnt=cnt-(a[r]-a[l++]);
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}

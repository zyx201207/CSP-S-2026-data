#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n,ans;
LL m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;++i){
		while(j<=n && a[j]-a[i]<=m) ++j;
		ans=max(ans,j-i);
	}
	printf("%d",ans);
	return 0;
}

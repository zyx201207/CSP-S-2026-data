#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans; ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++){
		while(l<r&&(r-l+1)*a[r]-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mx=0;
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;++i){
		int l=1,r=i,ans;
		while (l<=r){
			int mid=l+r>>1;
			if (a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid-1,ans=mid;
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	printf("%lld",mx);
	return 0;
}
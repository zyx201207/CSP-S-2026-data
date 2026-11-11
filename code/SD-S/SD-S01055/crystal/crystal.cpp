#include<bits/stdc++.h>
#define int long long
#define PLL pair<int,int>
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],ans=0;
bool chack(int l,int r){
	return a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int lst=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(chack(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}

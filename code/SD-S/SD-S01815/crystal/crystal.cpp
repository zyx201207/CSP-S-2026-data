#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +7;
#define ll long long
#define rnt register int
#define A first
#define B second
ll n,m,a[N],st[N],s[N],se[N],sum;
int ans=1;
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(rnt i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(rnt i=2;i<=n;++i) st[i]=abs(a[i]-a[i-1]);
	for(rnt i=2;i<=n;++i) s[i]=s[i-1]+st[i]*(i-1),se[i]=se[i-1]+st[i];
	for(rnt i=1;i<=n;++i){
		int l=i,r=n;
		while(l<r){
			int mid=((l+r+1)>>1);
			if(s[mid]-s[i]-(i-1)*(se[mid]-se[i])<=m) l=mid;
			else r=mid-1;
		}ans=max(ans,l-i+1);
	}
	cout<<ans;
}

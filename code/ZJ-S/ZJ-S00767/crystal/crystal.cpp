#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r>>1);
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int ans = 1;
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=1;
		while(l<=r){
			int mid=(l+r)/2,t=mid*a[i]-sum[i]+sum[i-mid];
			if(t<=m)l=mid+1,res=mid;
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
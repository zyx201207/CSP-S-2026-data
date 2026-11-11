#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn],fy[maxn],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		fy[i]=fy[i-1];
		while((i-fy[i])*a[i]-sum[i]+sum[fy[i]]>m){
			fy[i]++;
		}
		ans=max(ans,i-fy[i]);
	}
	cout<<ans<<'\n';
	return 0;
}

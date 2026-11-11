#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[600005],sum[600005],ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0,a[0]=0;
	for(int i=1;i<=n;i++)
	cin>>a[i],sum[i]=sum[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(((i-l+1)*a[i]-(sum[i]-sum[l]+a[l]))>m)l+=1;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
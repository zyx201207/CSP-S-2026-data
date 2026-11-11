#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,j=1,s;
int a[500005],sum[500005],f[500005];
bool flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) f[i]=(i-1)*a[i]-sum[i-1];//全部补成a[i]
	for(int i=1;i<=n;i++){
		if(f[i]<=m){
			ans=i;
			continue;
		}
		int y=f[i]-((a[i]-a[j-1])*(j-1)+f[j-1]);//y是需求量
		while(y>m && j<=n){
			s=a[i]-a[j];
			y-=s;
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
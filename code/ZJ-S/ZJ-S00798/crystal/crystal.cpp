#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005],n,m,ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,cnt=0;
	for(int r=1;r<=n;r++){
		cnt=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		while(cnt>m&&l<r){
			l++;
			cnt-=a[r]-a[l-1];
		}
		ans=max(ans,r-l+1);
	}
	if(ans==1) cout<<0;
	else cout<<ans;
	return 0;
} 

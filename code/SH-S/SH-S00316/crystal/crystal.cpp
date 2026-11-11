#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],f=1,ans,sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
	if(f){//teshuxingzhiAB
		for(int i=n-1;i>=1;i--)if(m>=a[n]-a[i])m-=a[n]-a[i],a[i]=a[n];
		int ans=0;for(int i=1;i<=n;i++)if(a[i]==a[n])ans++;
		cout<<ans;
		return 0;
	}
	else if(n*n<=1e8){
		int pre=1,j;
		for(int i=1;i<=n;i++){//ai is the level
			int mm=m,cnt=0;
			for(j=i;j>=pre;j--){
				if(a[i]==a[j]){
					cnt++;continue;
				}
				if(mm>=a[i]-a[j]){
					mm-=a[i]-a[j];
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);pre=j+1;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
//	int j=1;
//	while(j<=n&&(j-1)*a[i]-sum[j-1]<=m)j--;
	for(int i=n,j=n;i>=2;i--){//ai is the level
		while(j>=2&&(i-j)*a[i]-sum[i-1]+sum[j-1]<=m)j--;
//		while(j+1<=i&&j*a[i]-sum[j]>m)j++;
//		cout<<i<<" "<<j<<endl;
		ans=max(ans,i-j);
	}
	cout<<ans;
}

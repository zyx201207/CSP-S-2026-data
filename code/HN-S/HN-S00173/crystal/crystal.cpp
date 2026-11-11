#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=5e5+5;
int n,m,a[mn],ans,sum[mn],cnt;
signed main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool flag=true;
	int ac=a[1]-a[0];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]-a[i-1]!=ac) flag=false;
	}
	if(flag){
		int i=1;
			for(int k=1,j=i+1;j<=n;k++,j++){
				if((a[i]+a[j])*k>m*2){
					break;
				}
				ans=max(ans,k-i+2);
			}
	cout<<ans<<'\n';
		return 0;
	}
		for(int i=1;i<=n;i++){
			for(int k=1,j=i+1;j<=n;k++,j++){
				if(a[j]*k-sum[j]+sum[i-1]>m){
					break;
				}
				ans=max(ans,k-i+2);
			}
		}
	cout<<ans<<'\n';
	return 0;
}


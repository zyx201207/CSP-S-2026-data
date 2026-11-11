#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int j=1,ans=0;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-j+1)-(sum[i]-sum[j-1])>m&&j<=n){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
} 

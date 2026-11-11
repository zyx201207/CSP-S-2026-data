#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	int r=1,sum=0,ans=1;
	
	for(int l=1;l<=n;l++){
		while(r+1<=n&&sum+(r-l+1)*(a[r+1]-a[r])<=m){
			sum+=(r-l+1)*(a[r+1]-a[r++]);
		}
		ans=max(ans,r-l+1);
		
		sum-=a[r]-a[l];
	}
	cout<<ans;
	return 0;
}

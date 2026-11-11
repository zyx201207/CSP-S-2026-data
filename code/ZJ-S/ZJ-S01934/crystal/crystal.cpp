#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=0,sum=0;
	for(int r=1;r<=n;r++){
		while(l<r&&sum>m) sum-=a[r]-a[l],l++;
		if(sum<=m) ans=max(ans,r-l+1);
		sum+=(r-l+1)*(a[r+1]-a[r]);
	}	
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],l,r,cnt,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(l=1;l<=n;l++){
		while(r<n&&cnt+(r-l+1)*(a[r+1]-a[r])<=m){
			cnt+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		ans=max(r-l+1,ans);
		cnt-=a[r]-a[l];
	}
	cout<<ans;
	return 0;
} 
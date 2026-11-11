#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=0,cnt=0,js=0,ans=0;
	while(r<=n){
		while(r<=n&&cnt<=m){
			ans=max(ans,r-l+1);
			r++;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
		while(l<=r&&cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}

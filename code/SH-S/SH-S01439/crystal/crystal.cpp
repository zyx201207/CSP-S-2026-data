#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[1000010],ans,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r=n,l=n;
	while(r>0){
		while(l>1){
			if(cnt+a[r]-a[l-1]<=m)cnt+=a[r]-a[--l];
			else break;
		}
		ans=max(ans,r-l+1);
		cnt-=(r-l)*(a[r]-a[r-1]);
		r--;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,ans=0;
 int a[500010],sm[500010];
int bs(int l,int r,int x){
	int mid;
	while(l<r){
		mid=l+r>>1;
		if(a[x]*(x-mid+1)-(sm[x]-sm[mid-1])<=m)r=mid;
		else l=mid+1;
	}
	return r;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
		ans=max(ans,i-bs(1,i,i)+1);
	}
	cout<<ans;
	return 0;
}
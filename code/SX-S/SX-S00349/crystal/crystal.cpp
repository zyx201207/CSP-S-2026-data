#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sub[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sub[i]=sub[i-1]+a[i];
	int ans=-1,l=1,r=1;
	for(;r<=n;r++){
		if(a[r]==a[r+1])continue;
		while(l+1<=r and (r-l+1)*a[r]-(sub[r]-sub[l-1])>m)l++;
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<endl;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
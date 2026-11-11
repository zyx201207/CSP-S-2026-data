#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],ans,l,r;
bool check(int x){
	for(int i=x;i<=n;i++)if(a[i]*(x-1)-(s[i-1]-s[i-x])<=m)return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}

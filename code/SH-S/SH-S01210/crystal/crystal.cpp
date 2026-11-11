#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500005],s[500005];
bool check(int p,int r){
	return (r-p+1)*a[r+1]-s[r]+s[p-1]<=m;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,tmp;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i-1))tmp=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
}

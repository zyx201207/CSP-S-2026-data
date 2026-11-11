#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],p[500005];
bool check(int k){
	for(int i=k;i<=n;i++){
		int g=p[i]-p[i-k];
		if(a[i]*k-g<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}

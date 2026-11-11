#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],sum[500010];
int n,m;
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int res=x*a[i+x-1]-(sum[i+x-1]-sum[i-1]);
//		cout<<res<<' ';
		if(res>=0&&res<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
//		cout<<mid<<':';
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
}
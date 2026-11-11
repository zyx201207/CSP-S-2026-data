#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,inf=1e18+7;
int a[N];
int sum[N];
int n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(sum[i]-sum[i-x]+m>=a[i]*x)return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	int l=1,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	
	if(check(r))cout<<r;
	else cout<<l;
	
	return 0;
}
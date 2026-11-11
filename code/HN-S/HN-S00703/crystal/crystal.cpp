#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+1145;
int n,m,a[N],sum[N],ans;
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int x=a[i+mid-1]*mid;
		int y=sum[i+mid-1]-sum[i-1];
		if(x-y<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=1e18;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//luogu 991587
//H2O problem

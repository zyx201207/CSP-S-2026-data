#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
} 
int n,m,a[N],sum[N];
bool check(int x){
	int res=LLONG_MAX;
	for(int i=1;i<=n-x+1;i++)
		res=min(res,x*a[i+x-1]-(sum[i+x-1]-sum[i-1]));
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fast_read();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

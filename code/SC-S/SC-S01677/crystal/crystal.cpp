#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define db double
#define pii pair<int,int>
const int N=5e5+5;
ll a[N],n,m,sum[N],res;
bool check(ll l,ll r){
	return a[r]*(r-l+1)-sum[r]+sum[l-1]<=m;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,ans=i;
		while(l<=r){
			int mid=((l+r)>>1);
			if(check(mid,i)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
}
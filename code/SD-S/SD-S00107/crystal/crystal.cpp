#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=5e5+10;
ll a[N],c[N],sum[N];
ll n,m;
bool check(int k){
//	cout<<"k:"<<k<<"\n";
	rep(l,1,n-k+1){
		int r=l+k-1;
//		cout<<l<<" "<<r<<" "<<a[r]<<"\n";
		if(k*a[r]-(sum[r]-sum[l-1])<=m){
//			cout<<"Y\n";
			return 1;
		}
	}
//	cout<<"N\n";
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=-1;
	int l=1,r=n*2;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);			
			l=mid+1; 
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define print(a)cout<<#a<<"= "<<a<<"\n";
#define aprint(a,l,r)cout<<#a<<"= ";rep(i,l,r)cout<<a[i]<<", ";cout<<"\n";
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll n,m;
ll a[N],sum[N];
ll res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	rep(i,1,n)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		//cout<<i<<" "<<ans<<endl;
		res=max(res,i-ans+1);
	}	
	cout<<res;
	//cerr<<(double)clock()/CLOCKS_PER_SEC;
	return 0;
}
/*
froepen
chzx_AT AK NGOI!!!!!
14:48
*/
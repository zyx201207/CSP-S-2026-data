#include<bits/stdc++.h>
using namespace std;
const int N= 5e5+10;
#define ll long long
int n,ans=0;
ll a[N],m;
ll lcnt[N],sum[N];
ll Find(int x,int s){
	//cout<<"F "<<lcnt[x]<<" "<<x<<" "<< m <<" "<<a[x]<<" "<<sum[x-1-m]<<" "<<lcnt[x]-1ll*(x-1-m)*a[x]+sum[x-1-m]<<'\n';
	return lcnt[x]-1ll*(x-1-s)*a[x]+sum[x-1-s];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) lcnt[i]=lcnt[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,cot=0;
		while(l<=r){
			int mid=(l+r)>>1;
			//cout<<"W "<<i<<" " <<l<<" "<<r<<" "<<mid<<" "<<'\n';
			if(Find(i,mid)<=m){
				cot=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,cot+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

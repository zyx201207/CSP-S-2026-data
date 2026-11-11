#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],pre[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,mid,ans1=i;
		while(l<=r){
			mid=((l+r)>>1);
			ll a1=a[i]*(i-mid+1),b1=pre[i]-pre[mid-1];
			ll sum=a1-b1;
			if(sum<=m){
				ans1=mid;r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,(i-ans1+1));
	}
	cout<<ans;
	return 0;
}
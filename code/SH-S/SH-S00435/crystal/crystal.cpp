#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],pfix[N],ans=0;
bool pan(ll l,ll r){
	ll len=r-l+1;
	return (len*a[r]-(pfix[r]-pfix[l-1])<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);	
	for(ll i=1;i<=n;i++) pfix[i]=pfix[i-1]+a[i];
	for(ll i=1;i<n;i++){
		ll le=i+1,ri=n;
		while(le<=ri){
			ll mid=(le+ri)>>1;
			if(pan(i,mid)){
				ans=max(ans,mid-i+1);
				le=mid+1;
			}else ri=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 

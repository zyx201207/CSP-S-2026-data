#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m;
ll a[N],b[N],d[N];
ll cnt=0,x,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-1;i++) b[i]=a[i+1]-a[1];
	for(ll i=1;i<=n-1;i++) d[i]=b[i]+d[i-1];
	for(ll r=1;r<=n-1;r++){
		cnt=r*b[r]-d[r-1];
		if(cnt>m) continue;
		ans=r+1;
	}
	cout<<ans;
	return 0;
}
 

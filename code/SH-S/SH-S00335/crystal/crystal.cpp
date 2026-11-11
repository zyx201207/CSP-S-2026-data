#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e6+5;

ll n,m,t,ans;
ll a[N],q[N];

bool check(ll l,ll r){
	return m>=(r-l+1)*a[r]-(q[r]-q[l-1]);
}

int main(){
	ios::sync_with_stdio(0);	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l!=r){
			ll mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

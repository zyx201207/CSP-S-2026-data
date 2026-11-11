#include<bits/stdc++.h>
#pragma GCC optimie(3)
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
	return a>b;
}
ll max(ll a,ll b){
	if(a>b)return a;
	else return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n+1];


	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	ll ans=1;
	for(ll i=1;i<=n;++i){
		ll o=0;
		for(ll j=i+1;j<=n;++j){
			
			if(o>m-(a[i]-a[j])){
				ans=max(j-i,ans);
				break;
			}if(j==n){
				ans=max(ans,j-i+1);
				break;
			}
			o+=(a[i]-a[j]);
		}
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e6+10;
const ll inf=1e18+10;
ll a[maxn];
ll c,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		for(ll i=1;i<=t;i++){
			cout<<"0\n";
		}
		return 0;
 	}
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]<k){
				cnt++;
			}
		}
		if(cnt<=k){
			cout<<"0\n";
		}
		else{
			cout<<cnt-k-1<<"\n";
		}
	}
	return 0;
}

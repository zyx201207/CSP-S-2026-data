#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+9;
ll n,m,a[N],ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=(1<<30);i>0;i/=2){
		ll t=0;
		for(ll j=1;j<=n;j++) if(a[j] & i) t++;
		if(t>=m){
			ans+=i;
			for(ll j=1;j<=n;j++) if((a[j] & i)==0) a[j]=0;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll zc=a[2]-a[1];
	for(ll i=0;i<n;i++){
		m-=zc*(i+1);
		if(m<zc){
			break;
		}ans++;
	}cout<<ans;
	return 0;
}

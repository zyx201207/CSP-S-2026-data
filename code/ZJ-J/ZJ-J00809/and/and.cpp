#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200020];
map<ll,ll> mp[2];
ll n,ans,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0][(2<<30)-1]=0;
	for(int i=1;i<=n;i++){
		for(auto [k,v]:mp[(i+1)%2]){
			if(k<ans){
				continue;
			}
			if(v+1==m){
				ans=max(ans,k&a[i]);
				continue;
			}
			mp[i%2][k&a[i]]=v+1;
		}
	}
	cout<<ans;
}
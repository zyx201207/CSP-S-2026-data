#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=-1;
vector<ll> a;
int main(){
	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ll minn=0x3f3f3f3f,maxn=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		ll qwq;
		cin>>qwq;
		a.push_back(qwq);
		maxn=max(maxn,qwq);
		minn=min(minn,qwq);
	}
	for(ll i=minn;i<=maxn;i++){
		vector<ll> z;
		for(int j=0;j<n;j++){
			if(a[j]-i>0){
				continue;
			}else{
				z.push_back(abs(a[j]-i));				
			}
		}
		sort(z.begin(),z.end());
		ll aaa=0,mmm=m;
		for(int j=0;j<z.size();j++){
			if(mmm>=z[j]){
				aaa++;
				mmm-=z[j];
			}else{
				break;
			}
		}
		ans=max(ans,aaa);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005];
struct node{
	ll x, bit[35];
	void build(){
		for(ll j=0; j<=30; j++){
			if((x>>j)&1)bit[j]=1;
			else bit[j]=0;
		}
	}
	ll& operator[](ll x){
		return bit[x];
	}
};
vector<node>vec[2];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1; i<=n; i++)
		cin >> a[i];
	if(n<=20){
	ll maxn=0;
	for(ll x=(1<<m)-1; x<(1<<n); x++){
		vector<ll>vec;
		for(ll i=0; i<n; i++){
			if((x>>i)&1){
				vec.push_back(a[i+1]);
			}
		}
		if(vec.size()==m){
			ll ad=vec[0];
			for(ll i=1; i<m; i++)ad&=vec[i];maxn=max(maxn, ad);
		}
	}
	cout<<maxn;
	return 0;
	}
	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);
	for(ll i=1; i<=n; i++){
		node bi;
		bi.x=a[i];
		bi.build();
		vec[0].push_back(bi);
	}
	ll nxt=0;
	for(ll i=30; i>=0; i--){
		if(vec[nxt].size()==m)break;
		vec[nxt^1].clear();
		for(node v:vec[nxt]){
			if(v[i])vec[nxt^1].push_back(v);
		}
		if(vec[nxt^1].size()>=m)nxt^=1;
	}
	ll ans=vec[nxt][0].x;
	for(ll i=1; i<m; i++)ans&=vec[nxt][i].x;
	cout<<ans;
	return 0;
}


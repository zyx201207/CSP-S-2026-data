#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[2*N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

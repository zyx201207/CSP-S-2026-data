#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[200010];
ll ans;

ll cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++){
		ans=ans&a[i];
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll c,t;
ll n,d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ll dd=a[2]-a[1];
		ll op=d/dd;
		ll mm=(n-1)/op;
	//	if(mm*op==n-1) mm--;
		ll re=(op-1)*mm;
		cout<<re;
	}
	return 0;
}


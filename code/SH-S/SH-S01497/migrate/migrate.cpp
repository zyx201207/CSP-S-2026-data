#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000009;
ll x[N];
ll c,T,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		ll xd=abs(x[2]-x[1]);
		ll cnt=(floor)(d/xd);
		cnt=cnt*2-1;
		if(n-cnt<0||d<xd||cnt<=1) cout<<0<<endl;
		else cout<<n-cnt<<endl;
	}
	return 0;
}

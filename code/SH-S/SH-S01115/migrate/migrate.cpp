#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll x[N],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			ll n,d;
			cin>>n>>d;
			for(ll i=1;i<=n;i++)cin>>x[i];
			ll i0=2;
			while(x[i0]-x[1]<=d)i0++;
			cout<<n-i0+1<<'\n';
		}
	}
	return 0;
}

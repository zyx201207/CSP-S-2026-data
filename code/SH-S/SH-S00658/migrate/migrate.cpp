#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d,diff;
const ll N=200009;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;++z){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		diff=x[n]-x[n-1];
		ll maxx=(d/diff);
		ll ans=0;
		ll gothrough=maxx+maxx-1;
		ans=n-gothrough;
		if(maxx<=1) ans=0;
		cout<<ans<<endl;
	}
	return 0;
}

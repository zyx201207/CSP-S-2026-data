#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,c,t,u,v,ans;
struct G{
	ll u;
	ll v;

}g[1000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<n;i++){
			cin>>g[i].u>>g[i].v;

		}
		ans=n/d-1;
		if(ans<=1){
			cout<<1<<endl;
		}
		else{
			cout<<n/d-1<<endl;
		}






	}
	return 0;
}
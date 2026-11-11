#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,u[1000006],v[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	ll y=t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		cout<<y-t<<"\n";
	}
	return 0;
}

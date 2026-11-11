#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500010];
ll l[100010],r[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<ll>k[1010];
	for(ll i=1;i<=n;i++){
		ll ki;
		cin>>ki;
		for(ll j=1;j<=ki*2;j++){
			ll aj,tj;
			cin>>aj>>tj;
			k[i].push_back(tj);
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>l[i]>>r[i];	
		cout<<l[i]*w[i]+r[i]<<'\n'; 
	}
	return 0;
} 

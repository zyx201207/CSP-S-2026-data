#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[200005],k[200005],a[15][20005],t[15][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	while(q--){
		ll x,y,sum=0;
		cin>>x>>y;
		for(ll i=x;i<=y;i++){
			sum+=t[1][i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
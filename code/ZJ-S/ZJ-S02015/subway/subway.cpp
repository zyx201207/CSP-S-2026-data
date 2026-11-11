#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c,n,m,d,q,w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}

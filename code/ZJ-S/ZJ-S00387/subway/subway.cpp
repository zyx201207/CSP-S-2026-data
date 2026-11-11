#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N=5e5+5;
ll c,n,m,d,q;
ll a[505],w[505];
struct node{
	ll u,v;
}; 
vector<node> g;

int main(){
	//n是线路，m是地铁站 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll p;
		cin>>p;
		w[i]=p;
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll aa,tt;
			cin>>aa>>tt;
			a[aa]=tt;
		}
	} 
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+a[x]+a[y]<<endl; 
	}
}

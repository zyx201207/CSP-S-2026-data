#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
ll c,n,m,d,q;
ll w[N];
struct xs{
	ll k,a[N],t[N];
}node[N];
ll x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>node[i].k;
		for(ll j=1;j<=node[i].k;j++){
			cin>>node[i].a[j]>>node[i].t[j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	return 0;
}

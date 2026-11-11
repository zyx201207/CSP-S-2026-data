#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q,ti[505][505],w[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		ll k=0;
		cin >> k;
		for(int j=1;j<=k;j++){
			ll a=0,t=0;
			cin >> a >> t;
			ti[i][a] = t;
		}
	}
	while(q--){
		ll x=0,y=0;
		cin >> x >> y;
		cout << ti[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}


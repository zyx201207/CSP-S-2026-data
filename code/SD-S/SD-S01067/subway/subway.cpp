#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],k[505];
vector<pair<int,int> > a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			a[i].push_back({j,x});
			t[i].push_back({j,y});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[i][j].second+t[i][k].second<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d,q,w[2011],t,k[2010],a[2010][2010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t;
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<t*(w[x]+w[y]);
	}
	return 0;
}

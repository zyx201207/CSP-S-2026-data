#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[10000005],k[1000005],a[5005][5005],t[5005][5005];
signed main(){
	freopen("subway1.out","w",stdout);
	freopen("subway.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[j];j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	while(q--){
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		ans+=t[x][y];
		cout<<ans;
	}
	return 0;
}


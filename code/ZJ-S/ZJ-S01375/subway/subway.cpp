#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int c,n,m,d,q;
int w[N],k[N];
int a[N][200005],t[N][200005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int tt=1e18;
		for(int i=1;i<=n;i++){
			if(!t[i][x]||!t[i][y]) continue;
			tt=min(tt,t[i][x]+t[i][y]);
		}
		cout<<w[x]+w[y]+tt<<"\n";
	}
	return 0;
}
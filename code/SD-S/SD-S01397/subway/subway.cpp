#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e5+5;
int n,m,c,d,q,w[N],k[505],a[505][N],t[505][N],x[M],y[M],ans=1e9;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				ans=min(ans,w[x[r]]+w[y[r]]+t[i][j]);
			}
		}
	}
	for(int r=1;r<=q;r++){
		cout<<ans<<"\n";
	}
	return 0;
}

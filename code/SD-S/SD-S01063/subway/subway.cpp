#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,n,m,d,q;
int w[N],k[505],a[505][N],t[505][N],xx[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			xx[a[i][j]]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			xx[a[i][j]]=min(xx[a[i][j]],t[i][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y]+xx[x]+xx[y];
		cout<<ans<<'\n';
	}
	return 0;
}

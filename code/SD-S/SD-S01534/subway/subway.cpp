#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5,INF=0x3f3f3f3f;
int c,n,m,d,q,w[M],k,a[M],t[N][M],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=INF;
		for(int j=1;j<=n;j++){
			ans=min(ans,w[x]+w[y]+t[x][j]+t[y][j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

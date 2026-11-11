#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[100][100],b[100][100],w[N],k[N],x[N],y[N],ans[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>b[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans[i]+=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++){
			ans[i]+=b[j][x[i]]+b[j][y[i]-1];
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
} 

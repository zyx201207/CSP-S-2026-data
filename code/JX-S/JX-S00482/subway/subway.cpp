#include<bits/stdc++.h>
using namespace std;
long long n,m,q,d,in[200005],time_[5001][5001],a[5001][5001],g[3001][3001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>in[i];
		}
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++){
			int k0;
			cin>>k0;
			cin>>a[i][1]>>time_[i][a[i][1]];
			for(int j=2;j<=k0;j++){
				cin>>a[i][j];
				cin>>time_[i][a[i][j]];
				for(int ii=1;ii<j;ii++){
					g[a[i][j]][a[i][ii]]=g[a[i][ii]][a[i][j]]=min(time_[i][a[i][j]]+time_[i][a[i][ii]],g[a[i][ii]][a[i][j]]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(g[i][k]+g[k][j]<g[i][j]) {
						g[i][j]=g[j][i]=g[i][k]+g[k][j];
					}
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<g[x][y]+in[x]+in[y]<<"\n";
		}
	return 0;
}

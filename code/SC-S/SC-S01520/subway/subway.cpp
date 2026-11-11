#include<bits/stdc++.h>
using namespace std;
vector<long long> dt[500005],dw[500005];
int c,n,m,d,q;
long long ch[50005],zl[505][505],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ch[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)zl[i][j]=1e18;
	for(int u,i=1;i<=n;i++){
		cin>>u;
		for(int j=1,v,w;j<=u;j++){
			cin>>v>>w;
			for(int K=0;K<int(dt[v].size());K++){
				if(zl[dt[v][K]][i]>dw[v][K]+w){
					zl[dt[v][K]][i]=dw[v][K]+w;
				}
				zl[i][dt[v][K]]=zl[dt[v][K]][i];
			}
			dt[v].push_back(i);
			dw[v].push_back(w);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(zl[i][j]>zl[i][k]+zl[k][j])zl[i][j]=zl[i][k]+zl[k][j];
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		ans=1e18;
		for(int j=0;j<int(dt[u].size());j++){
			for(int k=0;k<int(dt[v].size());k++){
				if(zl[dt[u][j]][dt[v][k]]+dw[u][j]+dw[v][k]<ans)ans=zl[dt[u][j]][dt[v][k]]+dw[u][j]+dw[v][k];
			}
		}
		ans+=ch[u]+ch[v];
		cout<<ans<<"\n";
	}
	return 0;
}
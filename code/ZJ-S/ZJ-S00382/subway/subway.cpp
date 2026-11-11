#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5,INF=1e9;
int c,n,m,d,q,w[maxm],k[maxn],f[maxn][maxn],o[maxn][maxm],id[maxm];
vector<int>a[maxn],t[maxn];
inline int C(int x,int y,int p){return t[x][p]+t[y][p];}
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=(f[i][j]?f[i][j]:INF);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j],o[i][a[i][j]]=1;
			id[a[i][j]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(o[j][i]&&o[k][i]) f[j][k]=f[k][j]=C(j,k,i);
			}
		}
	}
	Floyd();
	while(q--){
		int x,y;cin>>x>>y;
		cout<<w[x]+t[id[x]][x]+f[id[x]][id[y]]+t[id[y]][y]+w[y]<<'\n';
	}
	return 0;
}
/*
By ZJ-S00382.
Luogu UID:1086453.
*/

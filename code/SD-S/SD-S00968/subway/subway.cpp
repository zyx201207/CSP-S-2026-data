#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[505];
int f[10505][10505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],f[i][i]=0;
	for(int i=m+1;i<=m+n;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=tmp;j++){
			int a,b;
			cin>>a>>b;
			f[i][a]=b;
			f[a][i]=b;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+f[x][y]+w[y]<<'\n';
	}
	return 0;
}

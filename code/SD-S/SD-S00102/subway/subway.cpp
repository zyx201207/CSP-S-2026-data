#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2086;
int C,n,m,d,q;
int w[N],k[N];
int f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;//注意m是地铁站数，n是线路数 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			f[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a,t;
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			f[i][a+n]=f[a+n][i]=t;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			if(f[i][k]==-1) continue;
			for(int j=1;j<=n+m;j++){
				if(f[k][j]==-1) continue;
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				if(f[i][j]==-1) f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		cout<<w[start]+w[end]+f[start+n][end+n]<<endl;
	}
	return 0;
}

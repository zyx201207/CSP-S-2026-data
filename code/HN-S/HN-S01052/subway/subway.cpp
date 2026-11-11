#include<bits/stdc++.h>
using namespace std;
const int N=555;
const int M=1111;
const int NM=2222;
struct S{
	int Y;
	long long Z;
};
int c,n,m,d,q,k[N];
long long s,u[M],f[M][M];
vector<S> g[NM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>u[i];
	for(int i=1;i<=n;i++){
		int l=0;
		cin>>l;
		for(int j=1;j<=l;j++){
			int y=0;
			long long z=0;
			cin>>y>>z;
			g[m+i].push_back({y,z});
			f[m+i][y]=z;
			f[y][m+i]=z;
		}
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			if(i!=j&&f[i][j]==0){
				f[i][j]=1e9;
				f[j][i]=1e9;
			}
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
				f[j][i]=f[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l=0,r=0;
		cin>>l>>r;
		cout<<u[l]+u[r]+f[l][r]<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int C,n,m,d,q,x,y,w[2*N],k[N],a[N][2*N],t[N][2*N],f[N][N];
#undef int
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#define int long long
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
		for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
		for(int I=1;I<=m;I++){
			for(int j=1;j<=m;j++){
				if(I==j)f[I][j]=0;
				else f[I][j]=1e17;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++)scanf("%lld%lld",&a[i][j],&t[i][j]);
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<j;l++){
					int A=a[i][j],B=a[i][l];
					f[A][B]=f[B][A]=min(f[A][B],t[i][j]+t[i][l]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",w[x]+w[y]+f[x][y]);
		}
	return 0;
}
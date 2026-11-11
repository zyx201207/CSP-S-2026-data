#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e2+10;
const int MAXM=5e5+10;
const long long INF=1e18;

int c,n,m,d,q;
int w[MAXM]={};
int t[MAXN][MAXM]={};
long long f[MAXN][MAXN]={};

int r[MAXM]={};
int s[MAXM][30]={};

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++) {
		scanf("%d",&w[i]);
	}
	for(register int i=1;i<=n;i++) {
		for(register int j=1;j<=n;j++) {
			if(i==j) {
				f[i][j]=0;
				f[j][i]=0;
			}
			else {
				f[i][j]=INF;
				f[j][i]=INF;
			}
		}
	}
	int A,T;
	for(register int z=1;z<=n;z++) {
		int K; cin>>K;
		for(register int i=1;i<=K;i++) {
			scanf("%d %d",&A,&T);
			t[z][A]=T;
			r[A]++;
			s[A][r[A]]=z;
		}
	}
	for(register int i=1;i<=m;i++) {
		for(register int x=1;x<=r[i];x++) {
			for(register int y=x+1;y<=r[i];y++) {
				if(f[s[i][x]][s[i][y]]>t[s[i][x]][i]+t[s[i][y]][i]) {
					f[s[i][x]][s[i][y]]=t[s[i][x]][i]+t[s[i][y]][i];
					f[s[i][y]][s[i][x]]=t[s[i][x]][i]+t[s[i][y]][i];
				}
			}
		}
	}
	for(register int i=1;i<=n;i++) {
		for(register int j=i+1;j<=n;j++) {
			for(register int k=1;k<=n;k++) {
				if(f[i][k]+f[k][j]<f[i][j]) {
					f[i][j]=f[i][k]+f[k][j];
					f[j][i]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--) {
		int x,y;
		scanf("%d %d",&x,&y);
		long long res=w[x]+w[y],tmp=INF;
		for(register int i=1;i<=r[x];i++) {
			for(register int j=1;j<=r[y];j++) {
				if(t[s[x][i]][x]+t[s[y][j]][y]+f[s[x][i]][s[y][j]]<tmp) {
					tmp=f[s[x][i]][s[y][j]]+t[s[x][i]][x]+t[s[y][j]][y];
				}
			}
		}
		res=res+tmp;
		printf("%lld\n",res);
	}
	return 0;
}

//subway 15.00
#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
const ll INF=1e18;
int __,n,m,d,q,x,y,z,w[M],c[M],a[M][20],t[M][20];
ll f[N][N];
inline void cmn(ll &x,ll y){y<x&&(x=y);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>__>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>z;
		while(z--){
			cin>>x>>y;
			a[x][c[x]]=i,t[x][c[x]]=y;
			c[x]++;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<c[i];j++)
			for(int k=j+1;k<c[i];k++)
				cmn(f[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cmn(f[i][j],f[i][k]+f[k][j]);
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=n;j++)
	//		cout<<f[i][j]<<" \n"[j==n];
	while(q--){
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<c[x];i++)
			for(int j=0;j<c[y];j++)
				cmn(ans,t[x][i]+t[y][j]+f[a[x][i]][a[y][j]]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//15.21
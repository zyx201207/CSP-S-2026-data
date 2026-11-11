#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005,M=5e5+5;
int w[M],k[N],a[N][N],t[N][N],x[100005],y[100005];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1e15;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			f[i][a[i][j]]=t[i][j];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]+f[k][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=0;
		ans+=w[x[i]];
		ans+=w[y[i]];
		ans+=f[x[i]][x[i]];
		ans+=f[x[i]][y[i]];
		cout<<ans<<endl;
	}
	return 0;
}

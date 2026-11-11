#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e4+100,maxm=5e5+100,inf=1e18;
ll xc,n,m,xd,q;
ll w[maxm],x[maxm],y[maxm],ans[maxm];
//ll a[510][maxn],t[510][maxn],k[510];
ll a,t,kk;
ll f[503][maxn],rd[maxn][23];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> xc >> n >> m >> xd >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];//x
	}
	
	
	
	//-------------------
	for(int i=1;i<=m;i++){
		rd[i][0]=0;
	}
	
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i+m]=0;
	}
	
	for(int i=1;i<=n;i++){
		cin >> kk;
		for(int j=1;j<=kk;j++){
			cin >> a >> t;
			f[i][a]=t;
			rd[a][0]++;
			rd[a][rd[a][0]]=i;
			//f[a][m+i]=t;
		}
	}
	
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[j][k]<f[i][j+m]){
					f[i][j+m]=f[i][k]+f[j][k];
					//f[j][i]=f[i][k]+f[j][k];
				}
			}
		}
	}
	//-------------------
	
	
	
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1;i<=q;i++){
		ans[i]+=w[x[i]]+w[y[i]];
		//ans[i]+=f[x[i]][y[i]];
	}
	
	ll flag;
	for(int i=1;i<=q;i++){
		flag=inf;
		for(int j=1;j<=rd[x[i]][0];j++){
			for(int k=1;k<=rd[y[i]][0];k++){
				flag=min(flag,f[rd[x[i]][j]][x[i]]+f[rd[y[i]][k]][y[i]]+
				f[rd[x[i]][j]][rd[y[i]][k]+m]);
			}
		}
		ans[i]+=flag;
	}
	
	for(int i=1;i<=q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}

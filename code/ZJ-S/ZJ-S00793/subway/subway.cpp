#include <bits/stdc++.h>
#define int long long
using namespace std;
int dt[20010][25];
int tz[20010];
int js[20010];
int dz[20010][510];
int lz[510][510];
int c,n,m,d,q;
int vis[510];
int dis[510][510];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>tz[i];
	}
	for(int i = 1;i<=n;i++){
		int ds;
		cin>>ds;
		for(int j = 1;j<=ds;j++){
			int zd,td;
			cin>>zd>>td;
			dz[zd][i] = td;
		    dt[zd][++js[zd]] = i;
		}
	}
	memset(lz,0x3f,sizeof(lz));
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<js[i];j++){
			for(int k = j+1;k<=js[i];k++){
				int rj = dt[i][j],rk = dt[i][k];
				lz[rj][rk] = min(lz[rj][rk],dz[i][rj] + dz[i][rk]);
				lz[rk][rj] = lz[rj][rk];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == j){
				lz[i][j] = 0;
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				lz[i][j] = min(lz[i][j],lz[i][k]+lz[k][j]);
			}
		}
	}

	for(int i =1;i<=q;i++){
		int lq,le;
		cin>>lq>>le;
		int sum = tz[lq] + tz[le];
		int ctt = 1e9;
		for(int j = 1;j<=js[lq];j++){
			for(int k = 1;k<=js[le];k++){
				int rj = dt[lq][j],rk = dt[le][k];
				ctt = min(ctt,lz[rj][rk]+dz[lq][rj]+dz[le][rk]);
			}
		}
		cout<<sum+ctt<<endl;
    }
    return 0;
}
		
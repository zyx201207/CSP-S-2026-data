#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int t[3000];
int ls[3000];
int u[3000];
int dis[3000][3000];
void floyed(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> t[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> ls[j] >> u[j];
			if(j>1) dis[ls[j-1]][ls[j]]=u[j-1]+u[j];
		}
	}
	floyed();
	for(int i=1;i<=q;i++){
		int h,tt;
		cin >> h >> tt;
		cout << t[h]+dis[h][tt]+t[tt] << "\n";
	}
}
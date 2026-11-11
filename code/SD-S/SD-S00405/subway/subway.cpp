#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3+10;
int c,n,m,d,q,w[N],t[N],ans[N][N];
bool vis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(ans,0x3f,sizeof(ans));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
		ans[i][i]=w[i];
		vis[i][i]=1;
	}
	for(int i = 1;i <= n;i ++){
		int k,a,prea,z;
		cin >> k >> a >> z;
		prea=a;
		t[a]+=z;
		for(int j = 2;j <= k;j ++){
			cin >> a >> z;
			t[a]+=z;
			vis[a][prea]=1;
			vis[prea][a]=1;
			ans[a][prea]=w[a]+w[prea];
			ans[prea][a]=w[a]+w[prea];
			prea=a;
		}
	}
	//cout << ans[1][1];
	if(c>=0){
		for(int k = 1;k <= m;k ++){
			for(int i = 1;i <= m;i ++){
				for(int j = 1;j <= m;j ++){
					if((!vis[i][k])||(!vis[k][j]))continue;
					if(ans[i][j]>ans[i][k]-w[k]-w[k]+ans[k][j]+t[k]+t[i]+t[j]){
						ans[i][j]=ans[i][k]-w[k]-w[k]+ans[k][j]+t[k]+t[i]+t[j];
						//vis[i][j]=1;
						//cout <<i << k<< j << ans[1][3]<< "\n";
					}
				}
			}
		}
		for(int i = 1;i <= q;i ++){
			int x,y;
			cin >> x >> y;
			cout << ans[x][y] << "\n";
		}
	}
	return 0;
}

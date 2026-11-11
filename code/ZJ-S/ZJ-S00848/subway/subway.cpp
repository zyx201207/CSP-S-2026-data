#include<bits/stdc++.h>
using namespace std;
const int N = 500;
const int M = 497999;
int w[M],k[N];
bool bj[N];
int a[N][M],t[N][M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
    	cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		cin >> k[i];
    	for(int j = 1;j<=k[i];j++){
	    	cin >> a[i][j] >> t[i][a[i][j]];
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		int ans = 0x3f3f3f3f;
		for(int i = 1;i<=n;i++){
			bool qd = 0,zd = 0;
			for(int j = 1;j<=k[i];j++){
				if(a[i][j]==x){
					qd = 1;
				}
				if(a[i][j]==y){
					zd = 1;
				}
				if(qd&&zd) break;
			}
			if(qd&&zd) bj[i]=1;
		}
		for(int i = 1;i<=n;i++){
			if(!bj[i]) continue;
			int sum = w[x]+w[y];
			sum+=t[i][x]+t[i][y];
		//	cout << w[x] << " "<< t[i][x] << " "<< t[i][y] << " "<< w[y] << "\n";
			ans = min(ans,sum);
		}
		int sum = w[x]+w[y]+t[1][x]+t[2][y]+t[2][2]+t[1][2];
		ans = min(ans,sum);
		cout << ans << "\n";
	}
	return 0;
}

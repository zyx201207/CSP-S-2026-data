#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1010;
int w[N];
int a[505][N * 2];
int cnt[N];
int x,y;
int c,n,m,d,q;
bool vis[N];
int dfs(int qd,int k,int ii,int jj){
	//cout << qd << " "<< k  << " "<< ii  << " "<< jj << endl;
	if(qd == y){
		return k;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 2 * a[i][0];j += 2 && (i != ii || j != jj)){
			if(a[i][j] == a[ii][jj]){
//				vis[a[ii][jj]] = 1;
				dfs(a[i][j],k + a[ii][jj + 1] + a[i][j + 1],i,j);
//				vis[a[ii][jj]] = 0;
			}
		}
	}
	for(int j = jj;j <= 2 * a[ii][0];j += 2){
		dfs(a[ii][j],k,ii,j);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c == 0){
		for(int i = 1;i <= m;i++){
			cin >> w[i];
		}
		bool f = false;
		for(int i = 1;i <= n;i++){
			cin >> a[i][0];
			if(a[i][0] <= 2){
				f = true;
			}
			for(int j = 1;j <= 2 * a[i][0];j++){
				cin >> a[i][j];
				cnt[j]++;
			}
		}
//		if(f == ture){
//			for(int k = 1;k <= q;k++){
//				cin >> x >> y;
//				int num = 0;
//				for(int i = 1;i <= n;i++){
//					for(int j = 1;j <= 2 * a[i][0];j += 2){
//						if(a[i][j] == x){
//							if(a[i][0] == 1){
//								
//							}
//						}]
//					}
//				}
//			}
//		}			
		for(int k = 1;k <= q;k++){
			cin >> x >> y;
			int num = 0,ans = 0x3f3f3f3f;
			memset(vis,0,sizeof(vis));
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= 2 * a[i][0];j += 2){
					if(a[i][j] == x){
						vis[a[i][j]] = 1;
						num = num + w[x] + a[i][j + 1];
						int ly = dfs(x,num,i,j);
						ans = min(ly,ans);
						cout << ans;
					}
				}
			}
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 350;
int c, n, m, d, q;
int k[510], a[510][maxn], t[510][maxn], w[510];
ll dis[51][50][51][50];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
//	初始化 
	memset(dis, 0x3f, sizeof dis);
	for(int i1 = 1;i1 <= n;i1++)
		for(int i2 = 1;i2 <= m;i2++)
			dis[i1][i2][i1][i2] = 0;
//	读入+存边  
	for(int i = 1;i <= m;i++)
		cin>>w[i];
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		for(int j = 1;j <= k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
		for(int j = 2;j <= k[i];j++){
			dis[i][a[i][j - 1]][i][a[i][j]] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 2;j <= n;j++){
			dis[j][i][j - 1][i] = t[j][i] + t[j - 1][i];
			dis[j - 1][i][j][i] = t[j][i] + t[j - 1][i];
		}
	}
//	神秘暴力floyd 
		for(int k1 = 1;k1 <= m;k1++)
			for(int k2 = 1;k2 <= n;k2++)
				for(int i1 = 1;i1 <= m;i1++)
					for(int i2 = 1;i2 <= n;i2++)
						for(int j1 = 1;j1 <= m;j1++)
							for(int j2 = 1;j2 <= n;j2++)
								if((k1 != i1 || k2 != i2) && (i1 != j1 || i2 != j2) && (k1 != j1 || k2 != j2))
									dis[i2][i1][j2][j1] = min(dis[i2][i1][j2][j1], dis[i2][i1][k2][k1] + dis[k2][k1][j2][j1]);				
//	输出							
	while(q--){
		ll x, y, ans = 0, l, r;
		cin>>x>>y;
		ans += w[x] + w[y];
		ll minn = 1e18L;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)
				if(dis[i][x][j][y] < minn){
					minn = dis[i][x][j][y];
					l = i, r = j;
				}
		}
		ans += t[l][x] + t[r][y];
		ans += minn;
		cout<<ans<<"\n";
	} 
	return 0;
}
//CCF = Chinese Can Fly!!! = CPL Can Fly!!!!!!!


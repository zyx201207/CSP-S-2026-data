#include<bits/stdc++.h>
using namespace std;
int vis[100010];
//void dfs(int r,int st){
//	int cnt = 0;
//	int nx[10010];
//	for(int i = 1;i <= n;i++){
//		if(ce[st][i] == i){
//			nx[i] = t[i][st+1];
//			nx[2*i] = t[i][st-1];
//			cnt+=2;
//		}
//	}
//	sort(nx+1,nx+cnt+1);
//
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int a[100010];
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	int mp[510][50010];
	int k[10010];
	int t[510][50010];
	int ce[10010][n];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 2;j <= d;j+=2){
			cin >> mp[i][j/2];
			cin >> t[i][(j-1)/2];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[i];j++){
			ce[mp[i][j]][i] = i;
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int s[1010],g[1010];
		int sn=1,gn=1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k[i];j++){
				if(mp[i][j] == x){
					s[sn] = i;
					sn++;
				}
				if(mp[i][j] == y){
					g[gn] = i;
					gn++;
				}
			}
		}
		int ans[10010];
		//for(int i = 1;i <= sn;i++){
		//	ans[i] = dfs(s[i],x);
		//}
		cout << a[x]+a[y]+t[x][x]+t[x][y];
	}
	
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
struct node{
	int a,t;
};
node st[505][20005];
bool vis[505];
int mint = 1e8;
int findl(int loc){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[j];j++){
			if(st[i][j].a == loc){
				return i;
			}
		}
	}
}
int findr(int loc){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[j];j++){
			if(st[i][j].a == loc){
				return j;
			}
		}
	}
}
void dfs(int x,int nt,int e,int l){
	if(x == e){
		mint = min(mint,nt);
		return;
	}
	if(vis[l]) return;
	vis[l] = 1;
	for(int i = 1;i <= k[l];i++){ 
		for(int j = 1;j <= n;j++){
			for(int z = 1;z <= k[j];z++){
				if(st[j][z].a == st[l][i].a){
					dfs(st[j][z].a,nt+st[l][i].t+st[j][z].t,e,j); 
				}
			}
		}
	}
}
/*1145141008610191526143418999asdfghjklqwertywaxcuiopzxcvbnmxc*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i]; 
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> st[i][j].a >> st[i][j].t;
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		ll ans = w[x]+w[y];
		mint = 1e8;
		memset(vis,0,sizeof vis);
		dfs(x,0,y,findl(x));
		ans += mint;
		ans += st[findl(x)][findr(x)].t;
		ans += st[findl(y)][findr(y)].t;
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/

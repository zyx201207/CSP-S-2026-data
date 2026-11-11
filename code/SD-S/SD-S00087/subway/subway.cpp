#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,r;
int Ck[20004];//站厅到出口 时间 
int Zt[20004][512];//站厅到站台 时间 
int Nb[512][20004];
int bN[20004][512];//lll
int Sta[114514],Fin[114514];//起点终点 
int Vis[500010];
int ans;
void dfs(int x,int y,int step){
	Vis[x] = 1;
	if(x == y){
		ans = min(ans,step);
		return;
	}
	for(int i = 1; i <= bN[x][0]; i++){
		for(int j = 1; j <= Nb[bN[x][i]][0]; j++){
			int zhan = Nb[bN[x][i]][j];
			if(!Vis[zhan]){
				dfs(zhan,y,step+Zt[x][bN[x][i]]+Zt[zhan][bN[x][i]]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&r);
	for(int i = 1; i <= m; i++) scanf("%d",&Ck[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d",&Nb[i][0]);
		for(int j = 1; j <= Nb[i][0]; j++){
			int x;
			scanf("%d",&x);
			Nb[i][j] = x;
			bN[x][++bN[x][0]] = i;
			scanf("%d",&Zt[x][i]);
		}
	}
	for(int i = 1; i <= r; i++){
		scanf("%d%d",&Sta[i],&Fin[i]);
	}
	if(c<=11){
		for(int i = 1; i <= r; i++){
			for(int k = 1; k <= m; k++) Vis[k] = 0;
			ans = 2147483647;
			dfs(Sta[i],Fin[i],Ck[Sta[i]]+Ck[Fin[i]]); 
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
put:
32 
17
*/

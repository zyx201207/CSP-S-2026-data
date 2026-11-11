#include <iostream>
#include <vector> 
#include <cstdio>
using namespace std;

#define N 505

int c,n,m,d,q;
vector<int> line[N];
int w[N],toline[N][N],g[N][N],f[N][N];

int main(){/*
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);*/
	for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) g[i][j] = 2147483640;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int a = 0;a < N;a++) toline[a][i] = 2147483640;
		for(int j = 1;j <= k;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			line[i].push_back(a);
			toline[a][i] = t;
		}
	}
	for(int i = 1;i <= m;i++){
		g[1][i] = w[i];
		g[i][1] = w[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < line[i].size();j++){
			for(int k = 0;k <= j;k++){
				g[line[i][j]][line[j][k]] += toline[j][i] + toline[k][i];
				g[line[j][k]][line[i][j]] += toline[j][i] + toline[k][i];
			}
		}
	}
	for(int k = 1;k <= m;k++){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++){
				if(f[i][k] + f[k][j] > f[i][j]){
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",f[x][y]);
	}
	return 0;
}

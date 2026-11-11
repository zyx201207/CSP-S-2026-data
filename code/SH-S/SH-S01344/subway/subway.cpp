#include<bits/stdc++.h>
using namespace std;

const int N = 2e4+10;;

int c,n,m,d,q;
int x,y;

struct node{
	int v,ditie;
};
int dtx[N][N];
int val[N][N];// i ¼¸ºÅÏß j ÄÄÒ»Õ¾ 
vector<node> G[N];
int w[N];
int dis[N];

void dfs(int u,int xian){
	if(u == y){
		return;
	}
	
	for(auto i : G[u]){
		if(xian != i.xian);
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		for(int j= 1;j <= t;j++){
			cin >> dtx[i][j] >> val[i][dtx[i][j]];
		}
		for(int j = 1;j <= t;j++){
			for(int k = j + 1;k <= t;k++){
				G[dtx[i][j]].push_back({dtx[i][k],i);
				G[dtx[i][k]].push_back({dtx[i][j],i);
			}
		}
	}
	while(q--){
		memset(dis,-1,sizeof(dis)); 
		cin >> x >> y;
		dfs(x,0);
	} 
	
	return 0;
}

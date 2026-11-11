#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int w[MAXN];//zui hou jia
bool unvisited[MAXN]={true};
int p[1010][MAXN]; //第2i-1行为ai；第2i行为ti 
int plan[MAXN][2]; //1起点 2终点 
int timing[MAXN]; //empty!!
int findao[1010]; //找到的线路 
queue<int> t;

int findline(int x,int n){
	int k=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w[0];j++){
			if(p[2*i-1][j]==x){
				findao[k]=2*i-1;
				k++;
			}
		}
	}
	return k;
}

int bfs(int x,int n){
	int go = plan[x][1];
	int well = plan[x][2];
	int lin=0;
	int k;
	t.push(go);
	unvisited[go]=0;
	int tim=0;
		while(!t.empty()){
		int now = t.front();
		t.pop();
		if (now == well) return timing[now];
		if (unvisited[now]){
			k=findline(now,n);//找下一级并入队列 
			for(int i=k;i>0;i--){
				t.push(findao[i]);
				timing[now]=tim+p[lin][findao[i]];//时间+ti 
			}
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<=m;i++){
		cin >> w[i];
	}
	for(int i=0;i<=n;i++){
		cin >> p[2*i][0];
		for(int j=0;j<=w[0];j++){
			cin >> p[2*i-1][j];
			cin >> p[2*i][j];
		}
	}
	for(int i=0;i<=q;i++){
		cin >> plan[i][1];
		cin >> plan[i][2];
	}
	
	for(int i=0;i<=q;i++){
		int ans = bfs(i,n);
		cout << ans << endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
#define inf 500005
using namespace std;
struct edge{
	int nex,to,value;
}e[500005];
int c, n, m, d, q;
int head[500005],cnt;
void add(int from,int to,int value){
	cnt++;
	e[cnt].to=to;
	e[cnt].value=value;
	e[cnt].nex=head[from];
	head[from]=cnt;
	return;
}
int floyd[404][404];
void init(int m){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			floyd[i][j]=inf;
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	init(m);
	int w[500005] = {};
	int k;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	int a,t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d %d", &a, &t);
			floyd[i][a]=min(floyd[i][a],t);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]+floyd[k][k]);
			}
		}
	}
	int x,y;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &x, &y);
		cout<<w[x]+floyd[x][x]+floyd[x][y]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
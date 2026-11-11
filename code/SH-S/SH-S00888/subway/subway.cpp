#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q;
long long wss[120000];
bool vis[120000];
long long a[550][50],w[550][50]; // Ith Line Stage OR IthLine -> Ai's Middle
long long ww[550][55550];
int ki[650];
bool aval[650][33000];
long long hb[120000];
struct node{
	int pla;
	long long dis;
	bool friend operator < (node a, node b){
		return a.dis>b.dis; // Smaller Ones will be at the top 
	}
};
priority_queue <node> q; 
void bfs(int x, int y){
	memset(vis,0,sizeof(vis));
	memset(hb,0x3f,sizeof(hb));
	q.push({x,0});
	long long ans=1e17;
	hb[x]=0;
	while (!q.empty()){
		node qf=q.top();
		q.pop();
		if (qf.pla==y){
			ans=min(ans,wss[x]+wss[y]+qf.dis);
			//ans=min(ans,(wss[x]+wss[y]+qf.dis));
		}
		for (int i=1; i<=n; i++){
			if (aval[i][qf.pla]==1){
				for (int j=1; j<=ki[i]; j++){
					//if (vis[a[i][j]]==0){
					if (qf.dis+ww[i][qf.pla]+w[i][j] < hb[a[i][j]]){
						hb[a[i][j]]=qf.dis+ww[i][qf.pla]+w[i][j];
						q.push({a[i][j],qf.dis+ww[i][qf.pla]+w[i][j]});
					}
				}
			}
		}
	}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for (int i=1; i<=m; i++) cin >> wss[i];
	for (int i=1; i<=n; i++){
		cin >> ki[i];
		for (int j=1; j<=ki[i]; j++){
			cin >> a[i][j] >> w[i][j];
			aval[i][a[i][j]]=1;
			ww[i][a[i][j]]=w[i][j];
		}
	}
	for (int i=1; i<=Q; i++){
		int x,y;
		cin >> x >> y;
		bfs(x,y);
	}
}
/*
I Want to use PQ in this hp
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
I Tried My best here
Exp 100 + Eps + 0 + 0
I am SX I can't do T2 OR T3's T4's Partical as I have NO More Time
Good Luck Everyone

Furina YYDS Naxida YYDS

*/

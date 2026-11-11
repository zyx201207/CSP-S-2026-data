#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int w[510];
long long g1[510][510];
long long g2[510][510];
long long di[510][510];
bool t[510][510];
int c,n,m,d,q;
long long bfs(int s,int e){
	memset(di,127,sizeof(di));
	queue<pair<int,int> > q;
	for(int i = 1;i <= n;i++)
		if(t[s][i]){
			q.push({i,s});
			di[i][s] = w[s] + g2[i][s];
		}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 1;i <= n;i++)
			if(t[y][i]){
				if(di[i][y] > di[x][y] + g2[i][y] + g2[x][y]){
					di[i][y] = di[x][y] + g2[i][y] + g2[x][y];
					q.push({i,y});
				}
			}
		int yy = g1[x][y];
		if(di[x][yy] > di[x][y]){
			di[x][yy] = di[x][y];
			q.push({x,yy});
		}
	}
	long long ans = di[1][e] + w[e] + g2[1][e];
	for(int i = 2;i <= n;i++)
		ans = min(ans,di[i][e] + w[e] + g2[i][e]);
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++)
		cin>>w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		int xx = -1;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin>>x>>y;
			if(xx != -1)
				g1[i][xx] = x;
			g2[i][x] = y;
			t[x][i] = true;
			xx = x;
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<bfs(s,e)<<"\n";
	}
	return 0;
}
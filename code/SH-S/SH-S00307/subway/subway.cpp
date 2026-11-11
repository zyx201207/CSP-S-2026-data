#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,s;
};
int t[505][20005],a[505][20005],w[20005],h[505][20005],h1[20005][505],n,m;
bool b[505][20005];
queue <node> q;
void bfs(int st,int ed){
	for (int i=1;i<=n;i++){
		if (t[i][st]>1e9) continue;
		q.push({i,st,t[i][st]});
		b[i][st]=1;
	}
	while (!q.empty()){
		node x=q.front();
		//cout <<"a "<<x.x<<" "<<x.y<<" "<<x.s<<endl;
		if (x.y==ed){
			cout <<x.s+w[st]+w[ed]<<endl;
			return;
		}
		q.pop();
		for (int i=1;i<=n;i++){
			if (b[i][x.y]||t[i][x.y]>1e9) continue;
			b[i][x.y]=1;
			q.push({i,x.y,x.s+t[i][x.y]});
			//cout <<"b "<<i<<" "<<x.y<<" "<<x.s+t[i][x.y]<<endl;
		}
		for (int i=1;i<=m;i++){
			if (b[x.x][i]||t[x.x][i]>1e9) continue;
			b[x.x][i]=1;
			q.push({x.x,i,x.s+t[x.x][i]});
			//cout <<"b "<<x.x<<" "<<i<<" "<<x.s+t[x.x][i]<<endl;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,r,u,st,ed;
	memset(t,0x3f,sizeof t);
	cin >>c>>n>>m>>d>>r;
	for (int i=1;i<=m;i++){
		cin >>w[i];
	}
	for (int i=1;i<=n;i++){
		cin >>u;
		for (int j=1;j<=u;j++){
			cin >>a[i][j];
			h[i][a[i][j]]=1;
			cin >>t[i][a[i][j]];
		}
	}
	for (int i=1;i<=r;i++){
		cin >>st>>ed;
		bfs(st,ed);
		while (!q.empty()){
			q.pop();
		}
		memset(b,0,sizeof b);
	}
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int r;
}subway[501][21];
int f[501],ti[500001],dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},mp[501][21];
bool vis[501][21];
int c,n,m,d,q,x;
int start,end;
int bfs(int sx,int sy,int ex,int ey){
	vis[sx][sy]=1;
	for(int i=0;i<=3;i++){
		int x=sx+dx[i];
		int y=sy+dy[i];
		if(x>0&&x<=n&&y>0&&y<=f[x]&&vis[x][y]==0){
			if(x==sx){
				mp[x][y]=mp[sx][sy]+subway[x][y].t;
				bfs(x,y,ex,ey);
				vis[sx][sy]=0;
			}
			else if(sx!=ex) for(int j=1;j<=f[x];j++){
				if(subway[sx][sy].r==subway[x][j].r){
					mp[x][j]=mp[sx][sy]+subway[x][j].t;
					bfs(x,j,ex,ey);
					vis[sx][sy]=0;
				}
			}
		}
		if(x==ex&&y==ey){
			mp[ex][ey]=mp[sx][sy]+subway[x][y].t;
			return mp[ex][ey]+ti[subway[ex][ey].r];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ti[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		f[i]=x;
		for(int j=1;j<=x;j++){
			cin>>subway[i][j].r>>subway[i][j].t;
		}
	}
	while(q){
		node s,e;
		bool f1=0,f2=0;
		cin>>start>>end;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=f[i];j++){
				if(f1==1&&f2==1) break;
				if(subway[i][j].r==start&&f1==0){
					s.t=i;
					s.r=j;
					f1=1;
				}else if(subway[i][j].r==end&&f2==0){
					e.t=i;
					e.r=j;
					f2=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=21;j++){
				vis[i][j]=0;
				mp[i][j]=0;
			}
		}
		mp[s.t][s.r]=ti[subway[s.t][s.r].r]+subway[s.t][s.r].t;
		cout<<bfs(s.t,s.r,e.t,e.r)<<endl;
		q--;
	}
} 

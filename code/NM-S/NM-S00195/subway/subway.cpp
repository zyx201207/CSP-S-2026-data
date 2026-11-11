#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,d,q;
//测试点编号,地铁线路数,地铁站数,每个地铁站最多被几条线路经过,出行计划数
int w[N];
//依次表示从每个地铁站的地铁口走到站厅需要的时间
int x[N],y[N];
//第 r 个出行计划的起点和终点所在的地铁站编号
int k[N];
//第i条线路经过的地铁站数
int a[N][N],t[N][N];
//表示第i条线路经过的第j个地铁站,从该地铁站的站厅走到第i条线路的站台需要的时间
struct node{
	int id,time;
	string where_;
};
int bfs(int x,int y,int time){
	
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
    	cin >> k[i];
    	for(int j=1;j<=2*k[i];j++){
    		cin >> a[i][j] >> t[i][j];
		}
	}
//	for(int i=1;i<=q;i++){
//		cin >> x[i] >> y[i];
//		int ans=0x3f3f3f;
//		queue<node>q;
//		q.push({x[i],0,"Out"});
//		while(!q.empty()){
//			node u=q.top();
//			q.pop();
//			if(u.id=y[i]&&u.where_="Out"){
//				cout << u.time;
//				break;
//			}
//			if(u.where_=="Out"&&){
//				q.push({u.id,u.time+w[u.id],"Mid"});
//			}
//		}
//	}
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
		cout << w[x[i]]+w[y[i]]+t[x[i]]+t[x[i]];
	}
    return 0;
}

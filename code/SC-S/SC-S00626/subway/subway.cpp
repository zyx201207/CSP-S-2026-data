#include<bits/stdc++.h>//i+m:地铁口,i:站厅
using namespace std;
typedef pair<int,int> PII;
const int N=1.5e6+10;
struct node{
	int y,w;
};
int dis[N],dis1[1010][1010],idx;
vector<node> q[N];
priority_queue<PII,vector<PII>,greater<PII> > p;
priority_queue<PII,vector<PII>,greater<PII> > p1;
void dijstra(int s,int t){
	for(int i=1;i<=idx;i++) dis[i]=0x3f3f3f3f;
	p.push({0,s});
	dis[s]=0;
	while(!p.empty()){
		PII t=p.top();
		p.pop();
		int x=t.second;
		for(node t1:q[x]){
			int y=t1.y,w=t1.w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				p.push({dis[y],y});
			}
		}
	}
	cout<<dis[t]<<'\n';
}
void dijkstra1(int s){
	for(int i=1;i<=idx;i++) dis1[s][i]=0x3f3f3f3f;
	p1.push({0,s});
	dis1[s][s]=0;
	while(!p1.empty()){
		PII t=p1.top();
		p1.pop();
		int x=t.second;
		for(node t1:q[x]){
			int y=t1.y,w=t1.w;
			if(dis1[s][y]>dis1[s][x]+w){
				dis1[s][y]=dis1[s][x]+w;
				p1.push({dis1[s][y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x,y,w;
	int c,n,m,d,Q,k;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w;
		q[i].push_back({i+m,w});
		q[i+m].push_back({i,w});
	}
	idx=2*m;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>w;
			idx++;
			q[x].push_back({idx,w});
			q[idx].push_back({x,w});
			if(j>1){
				q[idx].push_back({y,0});
				q[y].push_back({idx,0});
			}
			y=idx;
		}
	}
	if(c<=8||c>=12){
		while(Q--){
			cin>>x>>y;//地铁口
			x+=m,y+=m;
			dijstra(x,y);
		}		
	}
	else{
		for(int i=1;i<=idx;i++) dijkstra1(i);
		while(Q--){
			cin>>x>>y;
			cout<<dis1[x+m][y+m]<<'\n';
		}
	}
	return 0;
}
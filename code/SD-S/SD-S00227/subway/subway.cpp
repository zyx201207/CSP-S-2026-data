/*
看着内存有点小炸的意思，但是但愿吧，不要炸
(双手合十) 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
//这是一个正确但复杂度极高的算法 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;

//dij
vector<pair<int,int> > ve[N];
int vis[N],dis[N];

//problem
int c,n,m,d,q;
int w,k;

void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	que.push({0,s});
	while(!que.empty()){
		int u=que.top().second;
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:ve[u]){
			int xx=v.first;
			if(dis[u]+v.second<dis[xx]){
				dis[xx]=dis[u]+v.second;
				que.push({dis[xx],xx});
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
	//这题的难点在于输入=)
	cin>>c>>n>>m>>d>>q;//输入的第一行包含5个... 
	for(int i=1;i<=m;i++){
		//输入的第二行包含m个正整数w1w2...wn
		//依次表示站->厅的时间
		cin>>w;
		ve[i].push_back({i+m,w});
		ve[i+m].push_back({i,w});
	}
	int id=2*m;
	for(int i=1;i<=n;i++){//n条地铁线路 
		cin>>k;
		int lst,t;
		cin>>lst>>t;
		ve[++id].push_back({lst+m,t});
		ve[lst+m].push_back({id,t});
		for(int j=2;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ve[++id].push_back({a+m,t});
			ve[a+m].push_back({id,t});
			ve[id-1].push_back({id,0});
			ve[id].push_back({id-1,0});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;
struct node{
	int frm,to,w;
	bool operator<(const node &nxt)const{
		return w>nxt.w;
	}
};
int c,n,m,d,q,x,y,w[500010],k[510],dis[410][410];
pair<int,int> que[100010];
vector<pair<int,int> > a[510],e[500010];
priority_queue<node> pq;
/*
c:测试点编号(0~25)
n:地铁线路数(1~500)
m:地铁站数(1~5e5)
d:每个地铁站最多被几条线路经过(1~20)
q:出行计划数(1~1e5)
w[i(1~m)]:i号地铁口走到站厅需要的时间(1~1e9)
k[i(1~n)]:i号地铁途经的站数(∑k<=5e5)
此处a[i][j]为a[i][j].first,t[i][j]为a[i][j].second 
	a[i(1~n)][j(1~k[i])]:i号地铁途径的第j个站(1~m)
	t[i(1~n)][j(1~k[i])]:i号地铁的站台到途径的第j个站的站厅所需的时间(1~1e9)
que[i(1~q)]:第i个问题从第que[i].first个地铁站到第que[i].second个地铁站(1~m)(que[i].first!=que[i].second)
*/
void dij(){
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=INT_MAX;
	for(int i=1;i<=n;i++)
		for(auto j:a[i])
			for(auto o:a[i]){
				dis[j.first][o.first]=0;
				dis[o.first][j.first]=0;
				pq.push({j.first,o.first,0});
				pq.push({o.first,j.first,0});
			}
	while(!pq.empty()){
		int frm=pq.top().frm,to=pq.top().to,w=pq.top().w;
		pq.pop();
		for(auto i:e[to]){
			auto indx=lower_bound(e[i.first].begin(),e[i.first].end(),i);
			int nto=i.first,nw=w+i.second+(*indx).first;
			if(dis[frm][nto]>nw){
				dis[frm][nto]=nw;
				pq.push({frm,nto,nw});
			}
		}
		for(auto i:e[frm]){
			auto indx=lower_bound(e[i.first].begin(),e[i.first].end(),i);
			int nfrm=i.first,nw=w+i.second+(*indx).second;
			if(dis[nfrm][to]>nw){
				dis[nfrm][to]=nw;
				pq.push({nfrm,to,nw});
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
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back({x,y});
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		que[i]={x,y};
	}
	for(int i=1;i<=n;i++)
		for(auto j:a[i])
			e[j.first].push_back({i,j.second});
	dij();
	for(int i=1;i<=q;i++)
		cout<<w[que[i].first]+dis[que[i].first][que[i].second]+w[que[i].second]<<'\n';
	return 0;
}
/*[(^v^)]*/

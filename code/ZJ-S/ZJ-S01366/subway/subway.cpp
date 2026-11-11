#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],tmd[(int)1e3+5][(int)1e3+5];
struct nodes{
	int a,t; 
};
vector <int> tf[N];
vector <nodes> rd[N]; 
struct BFS{
	struct node{
		int idx,val,tid; 
		bool operator < (const node& p) const {
			return val<p.val;
		} 
	};
	int query(int id,int x,int y){
		int ANS=0;
		int l=0,r=rd[x].size()-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(rd[x][mid].a<id) l=mid+1;
			else r=mid;
		}
		ANS+=rd[x][l].t;
		l=0,r=rd[y].size()-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(rd[y][mid].a<id) l=mid+1;
			else r=mid;
		}
		ANS+=rd[y][l].t;
		return ANS;
	}
	bool vis[505][1005];
	priority_queue <node> pq;
	void body(int bg){
		memset(vis,0,sizeof vis);
		for(int i=0;i<tf[bg].size();i++){
			pq.push({bg,w[bg]+(query(bg,tf[bg][i],tf[bg][i])/2),tf[bg][i]});
			vis[bg][tf[bg][i]]=true;
		}
		while(!pq.empty()){ 
			node now=pq.top();
			pq.pop();
			tmd[bg][now.idx]=min(tmd[bg][now.idx],now.val+w[now.idx]+(query(now.idx,now.tid,now.tid)/2));
			for(int i=0;i<tf[now.idx].size();i++){
				if(tf[now.idx][i]!=now.tid and vis[tf[now.idx][i]][now.idx]==false){
					pq.push({now.idx,now.val+query(now.idx,now.tid,tf[now.idx][i]),tf[now.idx][i]});
					vis[tf[now.idx][i]][now.idx]=true;
				}
			}
			for(int i=0;i<rd[now.tid].size();i++){
				if(vis[now.tid][rd[now.tid][i].a]==false){
					pq.push({rd[now.tid][i].a,now.val,now.tid});
					vis[now.tid][rd[now.tid][i].a]=true;
				}
			}
		}
		tmd[bg][bg]=0;
	}
}bfs;
bool cmp(nodes x,nodes y){
	return x.a<y.a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			tf[a].push_back(i);
			rd[i].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			tmd[i][j]=1e9;
	for(int i=1;i<=m;i++){
		bfs.body(i);
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout<<tmd[x][y]<<'\n';
	}
}

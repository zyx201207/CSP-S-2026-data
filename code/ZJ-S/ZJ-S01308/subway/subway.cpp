#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int text,n,m,d,T,x,y,dt1,w1;
int k[N],tq[N],dis1[1010][1010],dis2[N],vis[N];
vector<int> dt[520],w[520];
struct node1{
	int bh,w;
};
vector<node1> a[N];
struct node2{
	int x,t;
	bool operator<(const node2&rjl)const{
		return rjl.t<t;
	}
};
void bfs1(int qd){
	priority_queue<node2> q;
	q.push(node2{qd,0});
	dis1[qd][qd]=0;
	while(q.size()>0){
		int x=q.top().x;
		int t=q.top().t;
		q.pop();
		for(int i=0;i<a[x].size();i++){
			int bh=a[x][i].bh;
			int hf=a[x][i].w;
			for(int j=0;j<k[bh];j++){
				if(dt[bh][j]==x) continue;
				if(t+hf+w[bh][j]<dis1[qd][dt[bh][j]]){
					dis1[qd][dt[bh][j]]=t+hf+w[bh][j];
					q.push(node2{dt[bh][j],dis1[qd][dt[bh][j]]});
				}
			}
		}
	}
}
int bfs2(int qd,int zd){
	priority_queue<node2> q;
	q.push(node2{qd,0});
	memset(dis2,0x3f,sizeof dis2);
	memset(vis,0,sizeof vis);
	dis2[qd]=0;vis[qd]=1;
	while(q.size()>0){
		int x=q.top().x;
		int t=q.top().t;
		q.pop();
		if(x==zd) return t;
		for(int i=0;i<a[x].size();i++){
			int bh=a[x][i].bh;
			int hf=a[x][i].w;
			for(int j=0;j<k[bh];j++){
				if(dt[bh][j]==x||vis[dt[bh][j]]) continue;
				if(t+hf+w[bh][j]<dis2[dt[bh][j]]){
					dis2[dt[bh][j]]=t+hf+w[bh][j];
					vis[dt[bh][j]]=1;
					q.push(node2{dt[bh][j],dis2[dt[bh][j]]});
				}
			}
		}
	}
	return dis2[y];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>text>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>tq[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>dt1>>w1;
			dt[i].push_back(dt1);
			w[i].push_back(w1);
			a[dt[i][j]].push_back(node1{i,w[i][j]});
		}
	}
	if(text<=11){
		memset(dis1,0x3f,sizeof dis1);
		for(int i=1;i<=m;i++) bfs1(i);
		while(T--){
			cin>>x>>y;
			cout<<tq[x]+tq[y]+dis1[x][y]<<"\n";
		}
	}
	else{
		while(T--){
			cin>>x>>y;
			cout<<tq[x]+tq[y]+bfs2(x,y)<<"\n";
		}
	}
	return 0;
}
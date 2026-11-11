#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2000;
struct edge{
	int v,w;
	bool operator < (const edge ed)const{
		if(w<ed.w)return 1;
		else return 0;
	}
};
vector<edge>p[N];
int find(int a,int b){
	priority_queue<edge>bfs_; 
	vector<bool>vis(N,0);
	bfs_.push(p[a][0]);
	while(!bfs_.empty()){
		edge u=bfs_.top();
		bfs_.pop();
		if(u.v==b)return u.w;
		for(auto v:p[u.v]){
			if(!vis[v.v]){
				vis[v.v]=1;
				bfs_.push({v.v,v.w+u.w});
			}
		}
	}
	return -1;
}
int find_(int a,int b){
	queue<edge>bfs_; 
	vector<bool>vis(N,0);
	bfs_.push(p[a][0]);
	while(!bfs_.empty()){
		edge u=bfs_.front();
		bfs_.pop();
		if(u.v==b)return u.w;
		for(auto v:p[u.v]){
			if(!vis[v.v]){
				vis[v.v]=1;
				bfs_.push({v.v,v.w+u.w});
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(NULL),cout.tie(NULL);
	int c,m,n,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		p[i].push_back({i+m,w});
		p[i+m].push_back({i,w});
		//1->m地铁口,m+1->2m站台
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k==2){
			int w1,v1;cin>>w1>>v1;
			int w2,v2;cin>>w2>>v2;
			p[w2+m].push_back({w1+m,v1+v2});
			p[w1+m].push_back({w2+m,v1+v2});
		}
		else{
			for(int j=0;j<k;j++){
				int w,v,i_=i+2*m;cin>>w>>v;
				p[i_].push_back({w+m,v});
				p[w+m].push_back({i_,v});
				//2m+1->2m+n地铁线 
			}
		}
		
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(12<=c&&c<=19)cout<<find_(x,y)<<'\n';
		else cout<<find(x,y)<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Subway{
	int line,nx;
};
struct Bfs{
	int nod,sum;
};
struct Node{
	int far;
	vector<Subway> pre;
	vector<Subway> nxt;
	vector<int> v;
	#define far(i) node[i].far
	#define pre(i) node[i].pre.line 
	#define nxt(i) node[i].nxt.line
	#define pre(i) node[i].pre.nx 
	#define nxt(i) node[i].nxt.nx
	#define v(i) node[i].v
}node[N];
int w[N];
int c,n,m,d,q;
int sub[505][N];
int bfs(int x,int yend){
	bool v[N];
	int minx=0x3f3f3f;
	queue<Bfs> q;
	q.push({x,far(x)});
	while(!q.empty()){
		Bfs f=q.front();q.pop();
		if(f.nod==yend){
			minx=min(minx,f.sum);
			continue;
		}
		for(int i=0;i<nxt(f.nod).line.size();i++){
			int y=nxt(f.nod).nx;
			if(v[y])continue;
			v[y]=true;
			if(nxtline(f.nod)!=preline(f.nod))q.push({y,f.sum+2*far(y)});
			else q.push({y,f.sum+far(y)});
		}
	} 
	return minx;
}                                       
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			sub[i][j]=a;
			far(i)=t;
			v(a).push_back(i);
			nxt(sub[i][j-1]).line.push_back(i);
			nxt(sub[i][j-1]).nx.push_back(a);
			pre(i).line.push_back(i);
			pre(i).nx.push_back(sub[i][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,sum=0;cin>>x>>y;
		sum+=w[x]+w[y];
		sum+=bfs(x,y);
	}
	return 0;
} 
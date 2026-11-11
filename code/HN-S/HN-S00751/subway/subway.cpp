#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

long long idx,n,m,v,w,u,val[maxn],c,d,q,len,dist[maxn*2],ux,vx;
bool vis[maxn*2];

struct ed{
	long long v,w;
};

vector<ed> g[maxn*2];

struct pts{
	long long idx;
	long long dist;
	bool operator<(const pts&x)const{
		return x.dist<dist;
	}
};

void dijk(int x,int l){
	priority_queue<pts> q;
	for(int i=1;i<=idx;i++){
		vis[i]=0;
		dist[i]=0x3f3f3f3f;
	}
	dist[x]=0;
	q.push({x,0});
	while(!q.empty()){
		u=q.top().idx;
		q.pop();
		if(u==l){
			return;
		}
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(ed t:g[u]){
			v=t.v,w=t.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({v,dist[v]});
			}
		}
	}
}

void read(long long &x){
	char c='?';
	x=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		read(val[i]);
//		cin>>val[i];
	}
	idx=m;
	for(int i=1;i<=n;i++){
		read(len);
//		cin>>len;
		u=0;
		while(len--){
			read(v),read(w);
//			cin>>v>>w;
			idx++;
			g[v].push_back({idx,w});
			g[idx].push_back({v,w});
			if(u){
				g[u].push_back({idx,0});
				g[idx].push_back({u,0});
			}
			u=idx;
		}
	}
	while(q--){
		read(ux),read(vx);
//		cin>>ux>>vx;
		dijk(ux,vx);
		cout<<dist[vx]+val[ux]+val[vx]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/


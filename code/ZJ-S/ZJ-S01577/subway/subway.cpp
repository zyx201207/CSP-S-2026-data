#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,cnt=0,a[200005],t[200005],dis[200005],vis[200005];
struct node{
	int v,w;
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};
vector<node>g[200005];
priority_queue<node>pq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		node nw;
		nw.v=m+i,nw.w=w;
		g[i].push_back(nw);
		nw.v=i,nw.w=w;
		g[m+i].push_back(nw);
	}
	cnt=2*m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			node nw;
			nw.v=m+a[j],nw.w=t[j];
			g[++cnt].push_back(nw);
			nw.v=cnt,nw.w=t[j];
			g[m+a[j]].push_back(nw);
			if(j!=1){
				nw.v=cnt-1,nw.w=0;
				g[cnt].push_back(nw);
				nw.v=cnt,nw.w=0;
				g[cnt-1].push_back(nw);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
	    pq.push({x,0});
	    dis[x]=0,vis[x]=1;
	    while(pq.size()){
	    	node now=pq.top();
	    	pq.pop();
	    	for(node it:g[now.v]){
	    		if(dis[now.v]+it.w<=dis[it.v] && !vis[it.v]){
	    			dis[it.v]=dis[now.v]+it.w;
	    			pq.push({it.v,dis[it.v]});
	    			vis[it.v]=1;
				}
			}
		}
		cout<<dis[y]<<"\n";
	}
	return 0;
}

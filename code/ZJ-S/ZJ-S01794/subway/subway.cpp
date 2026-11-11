#include<bits/stdc++.h>
#define AKCSPS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define pii pair<int,int>
#define int long long
using namespace std;//44pts
const int N=500010;
int zt[N];
struct Edge{
	int to;
	int w;
};
vector<Edge> g[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int dij(int start,int end){
	vector<int> d(N,INT_MAX);
	d[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		pii c=pq.top();
		pq.pop();
		int du=c.first,uu=c.second;
		if(d[uu]<du)	continue;
		for(auto e:g[uu]){
			int vv=e.to,ww=e.w;
			if(d[vv]>d[uu]+ww){
				d[vv]=d[uu]+ww;
				pq.push({d[vv],vv});
			}
		}
	}
	return d[end];
}
signed main(){
	AKCSPS;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,t,q;
	cin>>c>>n>>m>>t>>q;
	//ÏßÂ·Õ¾Ì¨m+i
	for(int i=1;i<=m;i++){
		cin>>zt[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int keda,time;
			cin>>keda>>time;
			g[keda].push_back({m+i,time});
			g[m+i].push_back({keda,time});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+zt[x]+zt[y]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

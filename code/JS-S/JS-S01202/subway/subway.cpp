#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long>
const long long INF=1e17;
long long c,n,m,d,q,w[500005],k,dis[500005],vis[500005];
vector<pll> vec[500005];
void dijkstra(long long beg){
	for (long long i=1;i<=m+n;i++){
	    dis[i]=INF;
	    vis[i]=0;
	}
	dis[beg]=0;
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	pq.push(make_pair(0,beg));
	while(!pq.empty()){
		long long now=pq.top().second;
		pq.pop();
		if (vis[now])
		  continue;
		vis[now]=1;
		long long len=vec[now].size();
		for (long long i=0;i<len;i++){
			if (dis[vec[now][i].first]>dis[now]+vec[now][i].second){
				dis[vec[now][i].first]=dis[now]+vec[now][i].second;
				pq.push(make_pair(dis[vec[now][i].first],vec[now][i].first));
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (long long i=0;i<m;i++)
	  cin>>w[i];
	for (long long i=0;i<n;i++){
		cin>>k;
		for (long long j=0;j<k;j++){
			long long u,v;
			cin>>u>>v;
			vec[u].push_back(make_pair(m+i+1,v));
			vec[m+i+1].push_back(make_pair(u,v));
		}
	}
	for (long long i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		dijkstra(a);
		cout<<dis[b]+w[a-1]+w[b-1]<<endl;
	}
	return 0;
}

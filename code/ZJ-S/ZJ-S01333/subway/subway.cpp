#include<bits/stdc++.h>
using namespace std;
struct box {
	long long x,y,id,t;
};
long long c,n,m,d,q,w[500010];
vector<map<long long,long long> >dist(500010);
vector<vector<box > >edge(500010);
long long f(long long s,long long t) {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			dist[i][j]=1e16;
		}
	}
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	for(auto it:edge[s]) {
		q.push({s,it.id});
		dist[s][it.id]=it.t;
	}
	while(!q.empty()) {
		auto d=q.top();
		auto u=d.first,now=d.second;
		q.pop();
		box tmp;
		for(auto it:edge[u]) {
			if(it.id==now) {
				tmp=it;
				break;
			}
		}
		if(dist[tmp.x][now]>dist[u][now]) {
			dist[tmp.x][now]=dist[u][now];
			q.push({tmp.x,now});
		}
		if(dist[tmp.y][now]>dist[u][now]) {
			dist[tmp.y][now]=dist[u][now];
			q.push({tmp.y,now});
		}
		for(auto it:edge[u]) {
			if(it.id!=now) {
				if(dist[u][it.id]>dist[u][now]+tmp.t+it.t) {
					dist[u][it.id]=dist[u][now]+tmp.t+it.t;
					q.push({u,it.id});
				}
			}
		}
	}
	long long res=1e16;
	for(auto it:edge[t]) {
		res=min(res,dist[t][it.id]+it.t);
	}
	return res+w[s]+w[t];
}
int main() {
//	freopen("E:/down/subway/subway4.in","r",stdin);
//	freopen("E:/down/subway/subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		vector<long long>tmp1,tmp2;
		for(int j=1; j<=x; j++) {
			long long y1,y2;
			cin>>y1>>y2;
			tmp1.push_back(y1);
			tmp2.push_back(y2);
		}
		if(x==1) {
			edge[tmp1[0]].push_back({tmp1[0],tmp1[0],i,tmp2[0]});
		} else {
			edge[tmp1[0]].push_back({tmp1[0],tmp1[1],i,tmp2[0]});
			edge[tmp1[x-1]].push_back({tmp1[x-2],tmp1[x-1],i,tmp2[x-1]});
			for(int j=1; j<x-1; j++) {
				edge[tmp1[j]].push_back({tmp1[j-1],tmp1[j+1],i,tmp2[j]});
			}
		}
	}
	while(q--) {
		long long qs,qt;
		cin>>qs>>qt;
		cout<<f(qs,qt)<<endl;
	}
	return 0;
}
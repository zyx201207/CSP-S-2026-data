#include <bits/stdc++.h>
using namespace std;
long long no_need,xianlu,m,zmaxxian,t,u,v,w,zhans,a,b,zb=1,dist[20000007],uu[500005];
vector< pair<long long,long long> > g[2000006];
void d(int s,int e){
	priority_queue< pair<long long,long long>,vector< pair<long long,long long> >,greater< pair<long long,long long> > > q;
	q.push({0,s});
	dist[s] = 0;
	while(!q.empty()){
		long long distu = q.top().first;
		long long now = q.top().second;
		q.pop();
		for(long long i = 0;i < g[now].size();i++){
			long long ne = g[now][i].first;
			long long nw = g[now][i].second;
			if(dist[ne] > dist[now]+nw){
				dist[ne] = dist[now]+nw;
				q.push({dist[ne],ne});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> no_need >> xianlu >> m >> zmaxxian >> t;
	for(int i = 1;i <= m;i++){
		cin >> w;
		u = i+m+m;
		v = i+m;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i = 1;i <= xianlu;i++){
		cin >> zhans;
		for(int j = 1;j <= zhans;j++){
			cin >> uu[j] >> w;
			u = uu[j];
			v = u+m;
			if(dist[u] > 0){
				u = m+m+m+zb;
				uu[j] = u;
				zb++;
			}
			g[u].push_back({v,w});
			g[v].push_back({u,w});
			dist[u] = 1;
		}
		for(int j = 1;j < zhans;j++){
			g[uu[j]].push_back({uu[j+1],0});
			g[uu[j+1]].push_back({uu[j],0});
		}
	}
	for(int i = 1;i <= t;i++){
		cin >> a >> b;
		a += m+m;
		b += m+m;
		for(long long j = 0;j <= 3*m+zb+5;j++){
			dist[j] = LONG_LONG_MAX;
		}
		d(a,b);
		cout << dist[b] << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,t,s,wi[500005],dist[500505];
bool f[500505];
struct edge{
	int v,w;
	bool operator<(const edge&o)const{
		return w > o.w;
	}
};
vector <edge> e[500505];
void dl(int s){
	priority_queue <edge> q;
	q.push({s,0});
	memset(dist,0x3f,sizeof(dist));
	memset(f,0,sizeof(f));
	dist[s] = 0;
	while(!q.empty()){
        edge u = q.top();
        q.pop();
        if(f[u.v]) continue;
        f[u.v] = 1;
        for(auto ed:e[u.v]){
            if(dist[ed.v] > dist[u.v] + ed.w) dist[ed.v] = dist[u.v] + ed.w;
            q.push({ed.v,ed.w});
        }
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) cin >> wi[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++) {
			cin >> a >> t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
    for(int i=1;i<=q;i++) {
        cin >> s >> t;
        dl(s);
        cout << wi[s] + wi[t] + dist[t] << "\n";
    }
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,dis[500005][25],cnt[500005];
struct node{
	int c,id,w;
	bool operator<(const node&x)const{
		return w>x.w;
	}
};
vector<node>g[500005][25];
void dijk(int s){
	for(int i=1;i<=m;i++){
		for(int j=0;j<=cnt[i];j++) dis[i][j]=INT_MAX;
	}
	priority_queue<node>q;
	q.push({s,0,0});
	dis[s][0]=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		for(auto i:g[t.c][t.id]){
			if(dis[i.c][i.id]>dis[t.c][t.id]+i.w){
				dis[i.c][i.id]=dis[t.c][t.id]+i.w;
				q.push({i.c,i.id,dis[i.c][i.id]});
			}
		}
	}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		int v;
		cin >> v;
		cnt[i]=1;
		g[i][0].push_back({i,1,v});
		g[i][1].push_back({i,0,v});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		int lsta=0,lstc=0;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			cnt[a]++;
			g[a][1].push_back({a,cnt[a],t});
			g[a][cnt[a]].push_back({a,1,t});
			if(lsta!=0){
				g[a][cnt[a]].push_back({lsta,lstc,0});
				g[lsta][lstc].push_back({a,cnt[a],0});
			}
			lsta=a;
			lstc=cnt[a];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		dijk(x);
		cout << dis[y][0] << '\n';
	}
	return 0;
}
/*
100+40
while(1) RP++;
*/


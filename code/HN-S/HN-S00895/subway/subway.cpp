#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],cnt=0;
struct st{
	ll to,v;
};vector<st>g[500005];
vector<st>lx[500005];
struct st2{
	ll p,diss;
	bool operator < (const st2 &A)const{
		return A.diss<diss;
	}
};ll dis[2005][2005],b[1000005];
void dij(int sta){
	memset(b,0,sizeof(b));
	priority_queue<st2>q;
	q.push((st2){sta,0});
	dis[sta][sta]=0;
	while(q.size()){
		st2 now=q.top();
		q.pop();
		if(b[now.p])continue;
		b[now.p]=1;
		for(int i=0;i<g[now.p].size();i++){
			ll nto=g[now.p][i].to;
			ll vals=g[now.p][i].v;
			if(!b[nto]&&dis[sta][nto]>dis[sta][now.p]+vals){
				dis[sta][nto]=dis[sta][now.p]+vals;
				q.push((st2){nto,dis[sta][nto]});
			}
		}
	}return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;cin >> k;
		int now=i;
		for(int j=1;j<=k;j++){
			int x,y;cin >> x >> y;
			for(int i=0;i<lx[x].size();i++){
				int tolx=lx[x][i].to;
				int vals=lx[x][i].v;
				g[now].push_back({tolx,vals+y});
				g[tolx].push_back({now,vals+y});
			}lx[x].push_back({now,y});
		}
	}memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++)dij(i);
	while(q--){
		int sta,eda;
		cin >> sta >> eda;
		ll nowans=LONG_LONG_MAX/2;
		for(int i=0;i<lx[sta].size();i++){
			for(int j=0;j<lx[eda].size();j++){
				nowans=min(nowans,w[sta]+w[eda]+lx[sta][i].v+lx[eda][j].v+dis[lx[sta][i].to][lx[eda][j].to]);
			}
		}cout << nowans << '\n';
	}
	return 0;
}

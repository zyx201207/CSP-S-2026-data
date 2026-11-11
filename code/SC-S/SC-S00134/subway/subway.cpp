#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1;
ll n,m,c,d,q;
ll w[505];
ll sw[505][50005][2];
ll k[30];
struct node{
	ll nxt;
	ll v;
	ll w;
}e[2000005];
ll cnt=1;
ll head[500005];
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt++; 
}
ll du[500005];
ll nm;
vector<pair<ll,ll> > v[505];
void make_map(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
				int temp=nm;
				if(j>1){
					v[i].push_back({nm,0});
					nm++;
				}
				v[i].push_back({sw[i][j][0],sw[i][j][1]});
				if(j<k[i]){
					v[i].push_back({nm,sw[i][j][1]});
					nm++;
				}
				if(nm-temp==2){
					add(nm-2,nm-1,0);
					add(nm-1,nm-2,0);
				}
		}
		for(int j=1;j<v[i].size();j++){
			add(v[i][j].first,v[i][j-1].first,v[i][j].second);
			add(v[i][j-1].first,v[i][j].first,v[i][j].second);
		}		
	}

}
struct sour{
	ll v;
	ll c;
	bool operator <(const sour &a)const{
		return c>a.c;
	}
};
priority_queue<sour> que;
bool tong[500005];
ll dis[500005];
void dijkstra(ll s){
	memset(tong,0,sizeof(tong));
	memset(dis,0,sizeof(dis));
	que.push({s,0});
	while(que.size()){
		ll u=que.top().v;
		ll cost=que.top().c;
		que.pop();
		if(tong[u])continue;
		tong[u]=1;
		dis[u]=cost;
		for(int i=head[u];i;i=e[i].nxt){
			ll v=e[i].v;
			ll w=e[i].w;
			que.push({e[i].v,dis[u]+w});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>sw[i][j][0]>>sw[i][j][1];
		}
	}
	nm=m+1;make_map(1);
	//好绝望啊
	//时间和空间都爆了 
	//应该改成每次单独建图，这样不会爆空间，但是没有时间了 
	while(q--){
		int cx,cy;
		cin>>cx>>cy;
		ll ans=w[cx]+w[cy];
		dijkstra(cx);
		cout<<dis[cy]+ans<<"\n";
	}
	return 0;
}/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1;
ll n,m,c,d,q;
ll w[505];
ll sw[500005][2];
ll k[30];
struct node{
	ll nxt;
	ll v;
	ll w;
}e[4000005];
ll cnt=1;
ll head[500005];
void add(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt++; 
}
ll du[500005];
ll nm;
vector<pair<ll,ll> > v;
void make_map(int x){
	v.clear();
	for(int j=1;j<=k[x];j++){
			int temp=nm;
			if(j>1){
				v.push_back({nm,0});
				nm++;
			}
			v.push_back({sw[j][0],sw[j][1]});
			if(j<k[x]){
				v.push_back({nm,sw[j][1]});
				nm++;
			}
			if(nm-temp==2){
				add(nm-2,nm-1,0);
				add(nm-1,nm-2,0);
			}
	}
	for(int j=1;j<v.size();j++){
		add(v[j].first,v[j-1].first,v[j].second);
		add(v[j-1].first,v[j].first,v[j].second);
	}		
}
struct sour{
	ll v;
	ll c;
	bool operator <(const sour &a)const{
		return c>a.c;
	}
};
priority_queue<sour> que;
bool tong[500005];
ll dis[500005];
void dijkstra(ll s){
	memset(tong,0,sizeof(tong));
	memset(dis,0,sizeof(dis));
	que.push({s,0});
	while(que.size()){
		ll u=que.top().v;
		ll cost=que.top().c;
		que.pop();
		if(tong[u])continue;
		tong[u]=1;
		dis[u]=cost;
		for(int i=head[u];i;i=e[i].nxt){
			ll v=e[i].v;
			ll w=e[i].w;
			int cs=cost+w;
			que.push({e[i].v,cs});
		}
	}
}
int main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}nm=m+1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>sw[j][0]>>sw[j][1];
			make_map(i);
		}
	}
	while(q--){
		int cx,cy;
		cin>>cx>>cy;
		ll ans=w[cx]+w[cy];
		dijkstra(cx);
		cout<<dis[cy]+ans<<"\n";
	}
	return 0;
}
*/
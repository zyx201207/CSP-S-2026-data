#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int oo=1e9+5;
struct node{
	long long v,xl,d;
	bool operator <(const node &e)const{
		return d<e.d;
	}
};
long long w[100005],zt[505][505],cd;
vector<node> a[100005];
vector<long long> qd[100005];
long long dis[100005];
bool vis[100005];
priority_queue<node> qq;
void dj(long long s,long long l,long long zh){
	for(int i=1;i<=m;i++){
		dis[i]=oo;
		vis[i]=0;
	}
	dis[s]=0;
	qq.push({s,l,0});
	node u;
	while(!qq.empty()){
		u=qq.top();
		if(u.v==zh){
			cd=zt[u.xl][zh];
			//cout<<cd<<endl;
		}
		qq.pop();
		if(u.d>dis[u.v]){
			continue;
		}
		if(vis[u.v]==1){
			continue;
		}
		vis[u.v]=1;
		for(auto i:a[u.v]){
			//cout<<u.v<<' '<<dis[u.v]<<' '<<i.v<<' '<<dis[i.v]<<' '<<zt[u.xl][u.v]<<' '<<zt[i.xl][u.v]<<' '<<u.xl<<' '<<i.xl<<endl;
			if(i.xl!=u.xl){
				if(dis[u.v]+zt[i.xl][u.v]+zt[u.xl][u.v]<dis[i.v]){
					//cout<<u.v<<' '<<dis[u.v]<<' '<<i.v<<' '<<dis[i.v]<<endl;
					dis[i.v]=dis[u.v]+zt[i.xl][u.v]+zt[u.xl][u.v];
					qq.push({i.v,i.xl,dis[i.v]});
				}
			}else{
				dis[i.v]=dis[u.v];
				qq.push({i.v,i.xl,dis[i.v]});
			}
			//cout<<u.v<<' '<<dis[u.v]<<' '<<i.v<<' '<<dis[i.v]<<' '<<zt[u.xl][u.v]<<' '<<zt[i.xl][u.v]<<' '<<u.xl<<' '<<i.xl<<endl;
		}
	}
	cd+=zt[l][s];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long tp,lst=0,x,y;
		cin>>tp;
		cin>>x>>y;
		lst=x;
		zt[i][x]=y;
		qd[x].push_back(i);
		for(int j=2;j<=tp;j++){
			cin>>x>>y;
			a[lst].push_back({x,i,oo});
			lst=x;
			zt[i][x]=y;
			qd[x].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		long long fr,to,ans=oo;
		cin>>fr>>to;
		for(auto j:qd[fr]){
			dj(fr,j,to);
			ans=min(ans,dis[to]+cd);
		}
		cout<<ans+w[fr]+w[to]<<endl;
	}
	return 0;
}

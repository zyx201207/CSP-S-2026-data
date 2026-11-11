#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=4e18;
const int N=5e5+5;
int n,m,q;
int w[N],k[N];
vector<int>a[N];
vector<int>t[N];
struct edge{
	int v,w;
};
struct point{
	int id,dis;
	bool operator <(const point &o)const{
		return dis>o.dis;
	}
};
vector<edge>ed[N];
vector<int> dijk(int st){
	vector<int>dis(m+1,INF);
	vector<bool>vis(m+1,false);
	priority_queue<point>que;
	dis[st]=0;
	que.push({st,dis[st]});
	while(!que.empty()){
		point pre=que.top();
		que.pop();
		int u=pre.id,d=pre.dis;
		if(vis[u])continue;
		vis[u]=true;
		for(edge e:ed[u]){
			int v=e.v,w=e.w;
			if(dis[v]>d+w){
				dis[v]=d+w;
				que.push({v,dis[v]});
			}
		}
	}
	return dis;
}
bool vis[3][N];
int c,d;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int p=1;p<=n;p++){
		cin>>k[p];
		for(int j=1;j<=k[p];j++){
			int x,y;
			cin>>x>>y;
			a[p].push_back(x),t[p].push_back(y);
		}
		if(c<=11){
			for(int i=0;i<k[p];i++){
				for(int j=i+1;j<k[p];j++){
					ed[a[p][i]].push_back({a[p][j],t[p][i]+t[p][j]});
					ed[a[p][j]].push_back({a[p][i],t[p][j]+t[p][i]});
				}
			}
		}
		if(c==20||c==21){
			for(int i=0;i<k[p];i++){
				vis[p][a[p][i]]=true;
			}
		}
	}
	if(c<=11){
		vector<vector<int> >dis(m+1,vector<int>(m+1,0));
		for(int i=1;i<=m;i++)dis[i]=dijk(i);
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<(dis[x][y]+w[x]+w[y])<<endl;
		}
		return 0;
	}
	else if(c<=15){
		while(q--){
			int x,y;
			cin>>x>>y;
			vector<int>dis=dijk(x);
			cout<<(dis[y]+w[x]+w[y])<<endl;
		}
		return 0;
	}
	if(n==2){
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=INF;
			int mn=INF;
			for(int i=1;i<=m;i++){
				if(!vis[1][i]||!vis[2][i])continue;
				mn=min(mn,t[1][i]+t[2][i]);
			}
			for(int i=1;i<=n;i++){
				if(!vis[i][x])continue;
				for(int j=1;j<=n;j++){
					if(!vis[j][y])continue;
					if(i==j)ans=min(ans,w[x]+w[y]+t[i][x]+t[j][y]);
					if(i!=j){
						ans=min(ans,w[x]+w[y]+mn+t[i][x]+t[j][y]);
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	if(n==1){
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+t[1][x]+t[1][y]<<endl;
		}
		return 0;
	}
	return 0;
}

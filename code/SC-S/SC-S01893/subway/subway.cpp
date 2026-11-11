#include<bits/stdc++.h>
using namespace std;
class qt{
public:
	int x,y,w;
	bool operator < (const qt&c)const{
		return x<c.x;
	}
}qt[100005];
int w[500005],c,n,m,d,zhl,k,xx[500005],tt[500005];
long long ans[100005],dis[500005],hc[505][505];
class nd{
public:
	int x;
	bool operator < (const nd&c)const{
		return dis[x]<dis[c.x];
	}
};
priority_queue<nd> q;
vector<pair<int,int> > v[500005];
vector<int> g[500005],x[505];
map<int,int> t[505];
bool vis[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>zhl;
	if(c<=11&&c){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>xx[j]>>tt[j];
				for(int l=j-1;l>=1;l--)
					v[xx[l]].push_back({xx[j],tt[l]+tt[j]}),
					v[xx[j]].push_back({xx[l],tt[l]+tt[j]});
			}
		}
		for(int i=1;i<=zhl;i++)cin>>qt[i].x>>qt[i].y,qt[i].w=i;
		sort(qt+1,qt+1+zhl);
		int p=-1;
		for(int i=1;i<=zhl;i++)
			if(qt[i].x!=p){
				p=qt[i].x;
				memset(dis,0x3f,sizeof(dis));
				memset(vis,false,sizeof(vis));
				dis[p]=0;
				q.push({p});
				while(!q.empty()){
					int tp=q.top().x;
					q.pop();
					if(vis[tp])continue;
					vis[tp]=true;
					for(auto i:v[tp])
						if(dis[i.first]>dis[tp]+i.second)
							dis[i.first]=dis[tp]+i.second,
							q.push({i.first}); 
				}
				ans[qt[i].w]=dis[qt[i].y]+w[p]+w[qt[i].y];
			}
			else ans[qt[i].w]=dis[qt[i].y]+w[p]+w[qt[i].y];
		for(int i=1;i<=zhl;i++)cout<<ans[i]<<"\n";
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(hc,0x3f,sizeof(hc));
	for(int i=1;i<=n;i++){
		cin>>k;
		int a,b;
		hc[i][i]=0;
		for(int j=1;j<=k;j++)
			cin>>a>>b,t[i][a]=b,g[a].push_back(i);
	}
	int aa=0,bb=0;
	for(int i=1;i<=m;i++)
		for(int j=g[i].size()-1;j>=1;j--)
			for(int k=j-1;k>=0;k--)
				aa=g[i][j],bb=g[i][k],
				hc[aa][bb]=hc[bb][aa]=min(hc[aa][bb],t[aa][i]*1ll+t[bb][i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				hc[i][j]=hc[j][i]=min(hc[i][j],hc[i][k]+hc[k][j]);
	for(int i=1;i<=zhl;i++){
		int a,b;
		cin>>a>>b;
		long long ans=1e17;
		for(int i:g[a])
			for(int j:g[b])
				ans=min(ans,w[a]+hc[i][j]+w[b]+t[i][a]+t[j][b]);
		cout<<ans<<"\n";
	}
	return 0;
}

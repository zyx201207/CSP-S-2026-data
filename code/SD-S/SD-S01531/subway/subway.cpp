#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int cc,n,m,d,qs,w[N],k[505],b[1010][1010],c[1010];
vector<int> a[510],t[510];
struct node{
	int v;
	int cost;
};
bool vis[5010];
vector<node> e[5010];
priority_queue<pair<int,int> >q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+9);
		t[i].resize(k[i]+9);
		for(int j=1;j<=k[i]/2;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(cc>=7&&cc<=11){
		memset(b,0x3f,sizeof(b));
		for(int i=1;i<=n;i++){
			e[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
			e[a[i][2]].push_back({a[i][2],t[i][1]+t[i][2]});
		}
		for(int i=1;i<=m;i++){
			memset(c,0x3f,sizeof(c));
			memset(vis,0,sizeof(vis));
			while(!q.empty()) q.pop();
			c[i]=0;
			q.push({0,i});
			while(!q.empty()){
				int x=q.top().second;
				q.pop();
				if(vis[x]) continue;
				vis[x]=1;
				for(int j=0;j<e[x].size();j++){
					int y=e[x][j].v;
					if(c[y]>c[x]+e[x][j].cost){
						c[y]=c[x]+e[x][j].cost;
						q.push({-c[y],y});
					}
				}
			}
			for(int j=1;j<=m;j++){
				b[i][j]=min(c[j],b[i][j]);
				b[j][i]=min(c[j],b[j][i]);
			}
		}
		int x,y;
		for(int i=1;i<=qs;i++){
			cin>>x>>y;
			cout<<b[x][y]+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}

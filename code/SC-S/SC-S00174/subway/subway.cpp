#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,N=505,INF=1e17;
int C,n,m,d,q,w[M],k[N],a[N][N],vs[N],dis[N][N];
struct node{int x,w;};
vector<node> v[M];
void dij(int st){
	for(int i=1;i<=n;i++)vs[i]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,st});dis[st][st]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vs[x])break;
		vs[x]=1;
		for(int i=1;i<=n;i++){
			if(a[x][i]<INF){
				if(dis[st][i]>dis[st][x]+a[x][i]){
					dis[st][i]=dis[st][x]+a[x][i];
					q.push({-dis[st][i],i});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,t;j<=k[i];j++)cin>>x>>t,
		v[x].push_back({i,t});
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=dis[i][j]=INF;
	for(int i=1;i<=m;i++){
		for(node j:v[i])
			for(node o:v[i])if(j.x!=o.x)
				a[j.x][o.x]=a[o.x][j.x]=min(a[j.x][o.x],j.w+o.w);
	}
	for(int i=1;i<=n;i++)dij(i);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int as=INF;
		for(node j:v[x])
			for(node o:v[y])
				as=min(as,j.w+o.w+dis[j.x][o.x]);
		cout<<as+w[x]+w[y]<<'\n';
	}
} 
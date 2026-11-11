#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+510,inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
int C,n,m,D,Q;
int u,c,x,y;
int w[N];
int k[N];
int d[505][505];
int dist[N];
bool vis[N];
vector<PII> v[N];
priority_queue<PII,vector<PII>,greater<PII> > q;
void dijkstra(int s){
	for(int i=1;i<=m+n;i++)
		dist[i]=inf,vis[i]=false;
	dist[s]=0;
	d[s-m][s-m]=0;
	q.push({0,s});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int dis=t.first,u=t.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(PII it:v[u]){
			int i=it.first,c=it.second;
			if(dis+c<dist[i]){
				dist[i]=dis+c;
				q.push({dist[i],i});
				if(i>m) d[s-m][i-m]=dist[i];
			}
		}
	}
}
int rd(){
	int sum=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0')
		sum=sum*10+ch-'0',ch=getchar();
	return sum;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	C=rd(),n=rd(),m=rd(),D=rd(),Q=rd();
	for(int i=1;i<=m;i++){
		w[i]=rd();
	}
	for(int i=1;i<=n;i++){
		k[i]=rd();
		for(int j=1;j<=k[i];j++){
			u=rd(),c=rd();
			v[u].push_back({m+i,c});
			v[m+i].push_back({u,c});
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++){
		dijkstra(m+i);
	}
	while(Q--){
		x=rd(),y=rd();
		int ans=inf;
		for(PII itx:v[x]){
			for(PII ity:v[y]){
				int xi=itx.first,yi=ity.first;
				int xw=itx.second,yw=ity.second;
				ans=min(ans,d[xi-m][yi-m]+xw+yw+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//O(n*mlongm+q*d*d)

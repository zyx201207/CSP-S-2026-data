#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=510;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,Q,x,y,k;
ll a,b,t,ans,w[N*N*2],dist[N],dst[N][N];
struct node{
	int p;
	ll w;
	bool operator <(const node a)const{
		return a.w<w;
	}
};
vector<node>P[N],G[N*N*2];
priority_queue<node>q;
void dij(int s){
	memset(dist,0x3f,sizeof dist);
	dist[s]=0,q.push({s,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.p;
		ll d=t.w;
		if(d>dist[u])continue;
		for(node i:P[u]){
			int v=i.p;
			ll w=i.w;
			if(dist[v]>d+w)
				dist[v]=d+w,q.push({v,d+w});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
//	cerr<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<Q<<endl;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a>>t,G[a].push_back({i,t});
	}
	for(int i=1;i<=m;i++){
		int len=G[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int A=G[i][j].p,B=G[i][k].p;
				ll C=G[i][j].w+G[i][k].w;
				P[A].push_back({B,C});
				P[B].push_back({A,C});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++)
			dst[i][j]=dist[j];
	}
	while(Q--){
		cin>>x>>y,ans=inf;
		for(node i:G[x]){
			int a=i.p;
			ll w1=i.w;
			for(node j:G[y]){
				int b=j.p;
				ll w2=j.w;
//				cerr<<(dst[a][b]==dst[b][a])<<endl;
				if(dst[a][b]==inf)continue;
				ans=min(ans,dst[a][b]+w1+w2);
			}
		}
		cout<<w[x]+w[y]+ans<<endl;
	}
	return 0;
}
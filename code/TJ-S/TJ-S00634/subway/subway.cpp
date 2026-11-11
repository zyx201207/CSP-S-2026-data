#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e4+10,M=510;
int c,n,m,d,p;
struct node{
	int v,l,w;
	bool operator <(const node &X) const{
		return w>X.w;
	}
};
vector<node> h[N][M];
int W[N];
int dist[N][M];
bool st[N][M];
void dj(int x,int y){
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[x][0]=0;
	priority_queue<node> q;
	q.push({x,0,0});
	while(q.size()){
		node u=q.top();
		q.pop();
		if(st[u.v][u.l]){
			continue;
		}
		st[u.v][u.l]=true;
		for(node i:h[u.v][u.l]){
			int v=i.v;
			int l=i.l;
			int w=i.w;
			if(dist[v][l]>dist[u.v][u.l]+w){
				dist[v][l]=dist[u.v][u.l]+w;
				q.push({v,l,dist[v][l]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		cin>>a>>t;
		h[a][0].push_back({a,i,t});
		h[a][i].push_back({a,0,t});
		int prea=a;
		for(int j=1;j<=2*k-1;j++){
			cin>>a>>t;
			h[prea][i].push_back({a,i,0});
			h[a][i].push_back({prea,i,0});
			h[a][0].push_back({a,i,t});
			h[a][i].push_back({a,0,t});
			prea=a;
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		int ans=W[x]+W[y];
		dj(x,y);
		ans+=dist[y][0];
		cout<<ans<<endl;
	}
	return 0;
}

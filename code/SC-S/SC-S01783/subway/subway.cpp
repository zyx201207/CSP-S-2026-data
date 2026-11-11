#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct Node{
	int v,pre;
	ll w;
}edge[N];

int head[N],node;
ll ww[N];
ll mp[500][500];
pair<int,ll> a[N];
ll dis[500][500];

void add(int u,int v,ll w){
	edge[++node].v=v;
	edge[node].w=w;
	edge[node].pre=head[u];
	head[u]=node;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>ww[i];
	memset(mp,0x3f,sizeof mp);
	memset(dis,0x3f,sizeof dis);
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v;
			ll w;
			cin>>v>>w;
			a[j]={v,w};
			for(int l=1;l<j;l++){
				mp[a[j].first][a[l].first]=mp[a[l].first][a[j].first]=min(mp[a[j].first][a[l].first],a[j].second+a[l].second);
				dis[a[j].first][a[l].first]=dis[a[l].first][a[j].first]=mp[a[j].first][a[l].first];
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]>=inf) continue;
			for(int j=1;j<=n;j++){
				if(dis[j][k]>=inf) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+ww[u]+ww[v]<<endl;
	}
	return 0;
}
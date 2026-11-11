#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=2e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M],t[N][M];
struct node{
	int y,z;
};
vector<node> v[N+M];
ll dis[N+M];
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		int tx=pq.top().second;
		ll tz=pq.top().first;
		pq.pop();
		if(tz>dis[tx]) continue;
		for(int i=0;i<v[tx].size();i++){
			int nx=v[tx][i].y;
			int nz=v[tx][i].z;
			if(dis[nx]>dis[tx]+nz){
				dis[nx]=dis[tx]+nz;
				pq.push({dis[nx],nx});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int x=m+i;
		for(int j=1,y,z;j<=k[i];j++){
			scanf("%d%d",&y,&z);
			v[x].push_back({y,z});
			v[y].push_back({x,z});
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

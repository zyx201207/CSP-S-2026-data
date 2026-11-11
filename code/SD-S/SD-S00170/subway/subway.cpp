#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7,M=1e8+7;
int c,n,m,d,q,w[N];
int k,a[N],t[N],x,y,dist[M];
int h[1005],idx=0,st[1005];
priority_queue<pair<int,int> > qu;

struct node{
	int v,w,nxt;
}edge[M];
void add(int ai,int bi,int ci){
	edge[++idx]={bi,ci,h[ai]};
	h[ai]=idx;
}
void dijkstra(int s,int e){
	memset(dist,0x3f,sizeof(dist));
	memset(st,0,sizeof(st));
	qu.push({0,s});
	dist[s]=0;
	while(!qu.empty()){
		int temp=qu.top().first,jc=qu.top().second;
		qu.pop();
		if(st[jc]==1) continue;
		st[jc]=1;
		for(int i=h[jc];i!=-1;i=edge[i].nxt){
			int jj=edge[i].v;
			if(dist[jc]+edge[i].w<dist[jj]){
				dist[jj]=dist[jc]+edge[i].w;
				qu.push({dist[jj],jj});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if(j!=1){
				add(a[j],a[j]+2*m*i,0);
				add(a[j-1]+2*m*i,a[j]+2*m*i,0);
				add(a[j]+2*m*i,a[j-1]+2*m*i,0);
				add(a[j]+2*m*i,a[j]+2*m*(i-1),0);
			}
			add(a[j]+2*m*i,a[j]+m+2*m*i,t[j]);
			add(a[j]+m+2*m*i,a[j]+2*m*i,t[j]);
			add(a[j]+m+2*m*i,a[j]+m+2*m*(i-1),0);
			add(a[j]+m+2*m*(i-1),a[j]+m+2*m*i,0);
		}
	}
	while(q--){
		cin>>x>>y;
		dijkstra(x+m,y+m);
		cout<<w[x]+w[y]+dist[y+m]<<endl;
	}
	return 0;
}/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/


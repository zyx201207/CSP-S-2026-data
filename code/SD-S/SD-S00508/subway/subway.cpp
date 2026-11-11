#include<bits/stdc++.h>
#define int long long


using namespace std;

const int N=6e5+5,M=1e6+5;
int n,m,w0[N];
int idx,e[M],ne[M],h[N],w[M];
int dis[N];

struct edge{
	int u,d;
};

bool operator<(edge x,edge y){
	return x.d>y.d;
}

void add(int a,int b,int c){
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
	w[idx]=c;
}

int dijkstra(int x,int y){
	priority_queue<edge>q;
	for(int i=1;i<=n+m;i++) dis[i]=1e18;
	dis[x]=0;
	q.push({x,0});
	while(q.size()){
		int u=q.top().u,d=q.top().d;
		q.pop();
		if(dis[u]<d) continue;
		for(int i=h[u];i;i=ne[i]){
			int v=e[i];
			if(dis[v]>d+w[i]){
				dis[v]=d+w[i];
				q.push({v,dis[v]});
			}
		}
	}
	return dis[y];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int C,d,q;
	cin>>C>>n>>m>>d>>q;//m:
	for(int i=1;i<=m;i++){
		cin>>w0[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,t;
			cin>>x>>t;
			add(i+m,x,t);
			add(x,i+m,t);
		}
	}
//	if(C>=7&&C<=11){
//		int st=0,en=0;
//		for(int i=m+1;i<=m+n;i++){
//			int k=0;
//			for(int j=h[i];j;j=ne[j]){
//				k++;
//			}
//			if(k==1){
//				if(!st) st=i;
//				else en=i; 
//			}
//		}
//		if(st){
//			dijkstra(st,en);
//			while(q--){
//				int x,y;
//				cin>>x>>y;
//				cout<<abs(st,en)<<"\n";
//			}
//		}else{
//			
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		if(C<7||C>11)
		cout<<dijkstra(x,y)+w0[x]+w0[y]<<"\n";
//		else 
	}
	return 0;
} 

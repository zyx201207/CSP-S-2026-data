#include<bits/stdc++.h>
using namespace std;
int w[500005];
bool b[500005];
long long dis[500005][3];
struct E{
	int V,W,f,T;
};
vector<E> v[500005];
void dij(int s){
	priority_queue<pair<int,pair<long long,int> >,vector<pair<int,pair<long long,int> > >,greater<pair<int,pair<long long,int> > > > pq;
	pq.push({s,{0,0}});
	while(!pq.empty()){
		pair<int,pair<long long,int> >pqt=pq.top();
		int u=pqt.first,D=pqt.second.first,l=pqt.second.second;
		pq.pop();
		if(D>dis[u][0])
		break;
		for(int i=0;i<v[u].size();i++){
			int vv=v[u][i].V,d=v[u][i].W,L=v[u][i].f;

			if((L==l||l==0||dis[vv][0]==0)&&b[vv]==0){
			d=0;
			pq.push({vv,{0,L}});
			if(dis[u][1]==0)
			dis[u][1]=l;
			dis[vv][1]=dis[u][1];
			dis[vv][2]=L;
			b[vv]=1;
		}
			if(dis[vv][0]>dis[u][0]+d){
				dis[vv][0]=dis[u][0]+d;
				pq.push({vv,{dis[vv][0],L}});
				if(dis[u][1]==0)
			dis[u][1]=l;
			dis[vv][1]=dis[u][1];
			dis[vv][2]=L;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			int aa;
			long long tt;
			scanf("%d%lld",&aa,&tt);
			for(int j=2;j<=k;j++){
				int a;
				long long t;
				scanf("%d%lld",&a,&t);
				v[a].push_back({aa,tt+t,i,t});
				v[aa].push_back({a,tt+t,i,tt});
				aa=a,tt=t;
		}
}
	for(int i=1;i<=q;i++){
		memset(b,0,sizeof(b));
		for(int j=1;j<=m;j++){
			dis[j][0]=1e18;
		}
		int x,y;
		scanf("%d%d",&x,&y);
		dis[x][0]=0;
		dij(x);
		if(dis[y][0]==1e18)
		dis[y][0]=0;
		long long ans=0;
		for(int i=0;i<v[x].size();i++){
			if(v[x][i].f==dis[y][1]){
			ans+=v[x][i].T;
		}
	}
	for(int i=0;i<v[y].size();i++){
			if(v[y][i].f==dis[y][2]){
			ans+=v[y][i].T;
		}
		}
	ans+=dis[y][0]+w[x]+w[y];
	printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
#define L(i,l,r,d) for(int (i)=(l);(i)<=(r);(i)+=(d))
#define R(i,l,r,d) for(int (i)=(r);(i)>=(l);(i)-=(d))

using namespace std;
const int N=5e5+5;
//const i64 INF=1ll<<61;

typedef long long i64;

void solve();
struct node{
	i64 w;
	int to;
};
int c,n,m,d,q,tot,k[505],a[505][505];
i64 w[N],t[505][505];
vector<pair<i64,int>> g[N];

//struct cmp{
//	bool cmp(node A,node B){
//		return A.w<B.w;
//	}
//};

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Test=1;
	//scanf("%d",&Test);
	while(Test--) solve();
	return 0;
}

void dij(int s,int t){
	vector<i64> dist(tot+1,1ll<<61);
	vector<bool> vis(tot+1,0);
	set<pair<i64,int>> pq;
	dist[s]=w[s];
	L(i,1,tot,1) pq.insert({dist[i],i});
	//pq.push({w[s],s});
	L(i,1,tot,1){
		//i64 ww=pq.top().w;
		int u=0;
		for(auto x:pq){
			if(!vis[x.second]){
				u=x.second;
				vis[x.second]=1;
				break;
			}
			else pq.erase({dist[x.second],x.second});
		}
//		printf("%d\n",u);
		//pq.erase(pq.end()-1);
		//if(u==t) break;
		for(auto v:g[u]){
			if(dist[u]+v.first<dist[v.second]){
				pq.erase({dist[v.second],v.second});
				dist[v.second]=dist[u]+v.first;
				//printf("%lld\n")
				pq.insert({dist[v.second],v.second});
			}
		}
	}
	printf("%lld\n",dist[t]+w[t]);
}

void solve(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	L(i,1,m,1) scanf("%lld",w+i);
	tot=m;
	L(i,1,n,1){
		scanf("%d",k+i);
		L(j,1,k[i],1){
			scanf("%d %lld",&a[i][j],&t[i][j]);
			g[a[i][j]].push_back({t[i][j],++tot});
			g[tot].push_back({t[i][j],a[i][j]});
			if(j>1){
				g[tot].push_back({0,tot-1});
				g[tot-1].push_back({0,tot});
			}
		}
	}
	L(i,1,q,1){
		int s,t;
		scanf("%d%d",&s,&t);
		dij(s,t);
	}
}
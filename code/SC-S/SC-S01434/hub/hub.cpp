#include<bits/stdc++.h>
using namespace std;
const int N=4005,mod=998244353,INF=2e9;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
vector<int>G[N];
int sz[N],dep[N];
bool vis[N];
int n,k;
int L[N],R[N],dis[N];
bool ok[N];
int bfs(){
	rep(i,1,n){
		ok[i]=0;
	}
	queue<int>q;
	rep(i,1,n){
		if(vis[i])	q.push(i),dis[i]=0;
		else dis[i]=INF;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(ok[u])	continue;
		ok[u]=1;
		for(auto v:G[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=min(dis[v],dis[u]+1);
				if(!ok[v]){
					q.push(v);
				}
			}
		}
	}
	int maxn=0;
	rep(i,1,n)	maxn=max(maxn,dis[i]);
	return maxn;
}
void solve(){
	cin>>n>>k;
	rep(i,1,n)	G[i].clear();
	rep(i,1,n-1){
		int a,b;
		cin>>a>>b;
		L[i]=a,R[i]=b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int res=INF;
	rep(S,1,(1<<n)-1){
		if(__builtin_popcount(S)==k){
			int cnt=0;
			rep(i,1,n){
				if((S>>(i-1))&1){
					vis[i]=1;
					cnt++;
				}else vis[i]=0;
			}
			rep(i,1,n-1){
				if(vis[L[i]]&&vis[R[i]]){
					cnt--;
				}
			}
			if(cnt<=2){
				res=min(res,bfs());
			}
		}
	}
	cout<<res<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	rep(i,1,T){
		solve();
	}
}
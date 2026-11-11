#include<bits/stdc++.h>
#define int long long
using namespace std;
#define inf 1000000007
struct edge{
	int to,val;
};
vector<edge> G[2000200];
int c,t,n,d,q,di[5050][5050],dis[5050][5050],ans,a[2000200];
bool operator < (const edge &u,const edge &v){
	return u.val<v.val;
}
priority_queue<edge> Q;
void Digital(int p){
	for(int i=1;i<=n;i++){
		di[p][i]=inf;
	}
	di[p][p]=0;
	Q.push({p,di[p][p]});
	while(!Q.empty()){
		int u=Q.top().to;
		int val=Q.top().val;
		Q.pop();
		for(int i=0;i<G[u].size();i++){
			int w=1;
			int v=G[u][i].to;
			if(di[p][v]>di[p][u]+w){
				di[p][v]=di[p][u]+w;
				Q.push({v,di[p][v]});
			}
		}
	}
}
bool vis[5050];
int cnt[5050];
int F(int s,int p,int k){
	if(k==dis[s][p]) cnt[p]++;
	for(int i=0;i<G[p].size();i++){
		if(!vis[G[p][i].to]){
			vis[G[p][i].to]=1;
			F(s,G[p][i].to,k+1);
		}
	}
}
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					G[i].push_back({j,1});
					G[j].push_back({i,1});
				}
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					G[i].push_back({j,1});
					G[j].push_back({i,1});
				}
			}
		}
		for(int i=1;i<=n;i++){
			Digital(i);
		}
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		F(1,1,0);
		for(int i=1;i<=n;i++){
			if(cnt[i]==1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

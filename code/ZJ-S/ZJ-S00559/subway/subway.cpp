#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=505,MAXM=500005,MAXQ=100005,MAXDIS=0x3f3f3f3f3f3f3f3f;
int n,m,c,d,Q;
ll w[MAXM],k,a[MAXN],t[MAXN],x[MAXQ],y[MAXQ],ans;
struct A{
	ll v,dis;
};
vector<A> e[MAXM];
struct node{
	ll id,dis;
	bool operator<(const node &_)const{
		return dis>_.dis;
	}
};
ll dis[MAXM];
priority_queue<node> q;
bool vis[MAXM];
void dij(int st){
	for(int i=1;i<=m;i++){
		dis[i]=MAXDIS;
		vis[i]=0;
	}
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		int u=now.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v;
			//cout<<v<<" "<<dis[v]<<" "<<dis[u]+e[u][i].dis<<"\n";
			if(dis[v]>dis[u]+e[u][i].dis){
				dis[v]=dis[u]+e[u][i].dis;
				q.push({v,dis[v]});
			}
		}
	}
}
ll f[405][405];
void Floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(!f[i][j]) f[i][j]=MAXDIS;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			for(int k=1;k<=m;k++){
				if(i==k or j==k) continue;
				
				if(f[i][k]!=MAXDIS and f[k][j]!=MAXDIS){
					//if(i==1 and k==2 and j==3) cout<<"***";
					//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][k]<<" "<<f[k][j]<<" "<<f[i][j]<<"\n";
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		if(m<=400){
			for(int j=1;j<=k;j++){
				for(int z=1;z<j;z++){
					f[a[z]][a[j]]=t[j]+t[z];
				}
			}			
		}
		else{
			for(int j=1;j<=k;j++){//end
				for(int z=1;z<j;z++){//st
					e[a[z]].push_back({a[j],t[j]+t[z]});
				}
			}			
		}
	}
	if(m<=400){
		Floyd();
		for(int i=1;i<=Q;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=Q;i++){
			ans=f[x[i]][y[i]]+w[x[i]]+w[y[i]];
			cout<<ans<<"\n";
		}		
	}
	else{
		for(int i=1;i<=Q;i++){
			cin>>x[i]>>y[i];
			dij(x[i]);
			ans=dis[y[i]]+w[x[i]]+w[y[i]];
			cout<<ans<<"\n";
		}		
	}
	return 0;
}
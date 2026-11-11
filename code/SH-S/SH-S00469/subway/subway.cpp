#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q2;
long long dis[500010],vis[500010],w[500010],D[510][510];
struct N{
	long long y,w;
};
bool operator < (N x,N y){
	return x.w>y.w; 
}
vector<N> V[500010];
vector<N> P[500010];
void dij(long long s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<N> q;
	dis[s]=0;
	q.push({s,dis[s]});
	while(q.size()){
		int x=q.top().y;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(auto p:V[x]){
			int y=p.y,w=p.w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q2;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long Q=++cnt;
		for(int j=1;j<=k;j++){
			long long A,T;
			cin>>A>>T;
			V[Q].push_back({A,T});
			V[A].push_back({Q,T});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i+m);
		for(int j=1;j<=n;j++){
			D[i][j]=D[j][i]=min(dis[j],D[i][j]);
		}
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=Q2;i++){
			long long s,e;
			cin>>s>>e;
			long long ans=2e18;
			for(auto p:V[s]){
				int y=p.y,w=p.w;
				for(auto I:V[e]){
					int y2=p.y,w2=p.w;
					ans=min(ans,2*w+D[y][y2]);
				}
			}
			cout<<ans+w[s]+w[e]<<"\n";
		}
		return 0;
	}
	else if(c>=20){
		long long ans=2e18;
		for(auto p:V[s]){
			int y=p.y,w=p.w;
			ans=min(ans,w+w+2+D[y][y+3]);
		}
		cout<<w[s]+w[e]+ans<<"\n";
	} 
	for(int i=1;i<=Q2;i++){
		long long s,e;
		cin>>s>>e;
		long long ans=2e18;
		for(auto p:V[s]){
			int y=p.y,w=p.w;
			for(auto I:V[e]){
				int y2=p.y,w2=p.w;
				ans=min(ans,w+w2+D[y][y2]);
			}
		}
		cout<<ans+w[s]+w[e]<<"\n";
	}
	return 0;
} 

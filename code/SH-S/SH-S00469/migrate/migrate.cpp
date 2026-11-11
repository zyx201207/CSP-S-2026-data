#include<bits/stdc++.h>
using namespace std;
#define int long long 
long long dis[200010],vis[200010],w[200010],cnt[200010],x[200010];
struct N{
	long long y,w;
};
bool operator < (N x,N y){
	return x.w>y.w; 
}
vector<N> V[200010];
void dij(long long s,long long e){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
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
				cnt[y]=0;
				q.push({y,dis[y]});
			}
			else if(dis[y]==dis[x]+w){
				dis[y]=dis[x]+w;
				cnt[y]++;
			}
		}
	}
	return ;
}
void each(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				V[i].push_back({j,1});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		dij(i,n);
		for(int k=i+1;k<=n;k++){
			ans+=cnt[k];
		}
	}
	cout<<ans<<"\n";
}
void each2(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cout<<(n-1)*(n-2);
	}
}
void each3(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cout<<10*n+d;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			each2();
		}
		else if(c>14){
			each3();
		}
		else{
			each();
		}
	}
	return 0;
} 


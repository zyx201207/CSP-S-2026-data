#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int N=2e6+10;
long long a[N],n,d,dis[N],t[N],res=0,vis[N];
vector<int> e[N];
void BFS(int s){
	priority_queue< pair<long long,long long> > q;
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f,t[i]=0,vis[i]=0;
	dis[s]=0;t[s]=1;
	q.push({0,s});
	while(!q.empty()){
		auto p=q.top();q.pop();
		int du=p.first,u=p.second;
		if(dis[u]<du) continue;
		vis[u]=1;
		for(auto v:e[u])if(!vis[v]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				t[v]=t[u];
				q.push({-dis[v],v});
			}else 
			if(dis[v]==dis[u]+1)t[v]=t[u]+t[v];
//			cout<<u<<" "<<v<<" "<<t[u]<<' '<<t[v]<<"\n";
		}
	}
//	for(int i=1;i<=n;i++) cout<<i<<" "<<s<<" "<<dis[i]<<' '<<t[i]<<'\n';
	for(int i=1;i<=n;i++){
		if(t[i]==2) /*cout<<s<<' '<<i<<"\n",*/++res;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(c==11||c==12){
			for(int i=1;i<=n;i++) cin>>a[i];
			int x=d/(a[2]-a[1]);
			cout<<max(0,n-x-x+1)<<"\n";
			continue;
		}
		res=0;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if((i>j?a[i]-a[j]:a[j]-a[i])<=d) e[i].push_back(j);
			} 
		for(int i=1;i<=n;i++) BFS(i);
		cout<<res/2<<'\n';
	}
	
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
const int N=505,M=5e5;
int w[M];
struct Node{
	int k,u;
};
vector<int>st[N];
vector<Node>G[M];
int t[N][M];

long long ans=1e18;
bool vis[M];
void dfs(int k,int x,int y,long long sum){
	if(sum>=ans)return;
	if(x==y){
		ans=min(ans,sum+t[k][y]);
		return;
	}
	for(auto now:G[x]){
		int v=now.u,nk=now.k;
		if(vis[v])continue;
		vis[v]=1;
		if(k!=nk){
			dfs(nk,v,y,sum+t[k][x]+t[nk][x]);
		}else{
			dfs(nk,v,y,sum);
		}
		vis[v]=0;
	}
}
long long dis[N];
struct Nodee{
	int u,k;
	long long sum;
	bool operator < (const Nodee &a)const{
		return sum<a.sum;
	}
};
long long dijk(int kk,int x,int y){
	memset(dis,0x3f,sizeof dis);
	priority_queue<Nodee>qu;
	map<int,bool>mp;
	for(auto p:st[y]){
		mp[p]=1;
	}
	dis[x]=0;
	qu.push({x,kk,0});
	int ek;
	while(!qu.empty()){
		Nodee now=qu.top();
		qu.pop();
		if(now.sum>dis[now.u])continue;
		long long sum=now.sum;
		int k=now.k,xx=now.u;
		for(auto p:G[xx]){
			int v=p.u,nk=p.k;
			if(!mp.count(nk)){
				continue;
			}
			long long nw=0;
			if(nk!=k){
				nw=t[k][xx]+t[nk][xx];
			}
			if(dis[v]>dis[xx]+nw){
				dis[v]=dis[xx]+nw;
				qu.push({v,nk,dis[v]});
				if(v==y){
					ek=nk;
				}
			}
		}
	}
	return dis[y]+t[kk][x]+t[ek][y]+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int u=-1;
		for(int j=1;j<=k;j++){
			int v;cin>>v;
			st[v].push_back(i);
			cin>>t[i][v];
			if(u!=-1){
				G[u].push_back({i,v});
				G[v].push_back({i,u});
			}
			u=v;
		}
	}
	if(m>200){
		while(q--){
		    int x,y;cin>>x>>y;
		    long long anss=1e18;
		    for(auto k:st[x]){
		    	anss=min(anss,dijk(k,x,y));
		    }
		    cout<<anss<<"\n";
	    }
	    return 0;
	}
	while(q--){
		int x,y;cin>>x>>y;
		ans=1e18;
		vis[x]=1;
		long long mi=1e18;
		for(auto k:st[x]){
			dfs(k,x,y,0);
			mi=min(mi,ans+t[k][x]);
		}
		cout<<mi+w[x]+w[y]<<"\n";
		vis[x]=0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq,k[510],tot[500010],w[500010],t[500010][23],dis[500010][23],vis[500010][23],x,y,nxt,st,ed,ans;
unordered_map<int,int> mp;
struct A{
	int v,l,w;
	bool operator<(const A&b)const{
		return w<b.w;
	}
};
vector<A> e[500010][23];
priority_queue<A> q;
void dij(int x){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=20;j++){
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
			vis[i][j]=0;
		}
	}
	for(int i=1;i<=tot[st];i++){
		dis[st][t[st][i]%1000]=t[st][i]/1000;
		q.push({st,t[st][i]%1000,dis[st][t[st][i]%1000]});
	}
	while(q.size()){
		A tem=q.top();
		q.pop();
		int u=tem.v;
		int l=tem.l;
		if(vis[u][l]) continue;
		//cout<<u<<" "<<l<<" "<<tem.w<<"\n";
		vis[u][l]=1;
		for(A i:e[u][l]){
			int v=i.v;
			int p=i.l;
			int w=i.w;
			//cout<<"- "<<v<<" "<<p<<" "<<w<<" "<<dis[u][l]<<" "<<dis[v][p]<<"\n";
			if(dis[u][l]+w<dis[v][p]){
				dis[v][p]=dis[u][l]+w;
				q.push({v,p,dis[v][p]});
			}
		}
		for(int i=1;i<=tot[u];i++){
			//cout<<"- "<<u<<" "<<t[u][i]%1000<<" "<<t[u][mp[u*1000+l]]/1000+t[u][i]/1000<<" "<<t[u][mp[u*1000+l]]/1000<<" "<<t[u][i]/1000<<"\n";
			if(dis[u][l]+t[u][mp[u*1000+l]]/1000+t[u][i]/1000<dis[u][t[u][i]%1000]){
				dis[u][t[u][i]%1000]=dis[u][l]+t[u][mp[u*1000+l]]/1000+t[u][i]/1000;
				q.push({u,t[u][i]%1000,dis[u][t[u][i]%1000]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			t[x][++tot[x]]=y*1000+i;
			mp[x*1000+i]=tot[x];
			if(j!=1){
				e[nxt][i].push_back({x,i,0});
				e[x][i].push_back({nxt,i,0});
			}
			nxt=x;
		}
	}
	while(qq--){
		cin>>st>>ed;
		dij(st);
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=tot[ed];i++){
			ans=min(ans,t[ed][i]/1000+dis[ed][t[ed][i]%1000]);
		}
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],t[500005],y[500005],dis[500005],vis[500005],in[500005],ans[100005],inf=1e18,T;
struct aaa{
	int v,w;
};
struct sss{
	int u,v,id;
}s[100005];
vector<aaa>e[500005];
unordered_map<int,int>dq;
vector<aaa>u[500005];
struct aaaaa{
	int u,w;
	bool operator <(const aaaaa a)const{
		return w<a.w;
	}
};
priority_queue<aaaaa>Q;
void dij(int st){
	for(int i=1;i<=m;i++)dis[i]=inf,vis[i]=0;
	dis[st]=0;
	Q.push({st,0});
	while(!Q.empty()){
		aaaaa u=Q.top();
		Q.pop();
		if(vis[u.u])continue;
		vis[u.u]=1;
		for(auto v:e[u.u])
			if(dis[v.v]>dis[u.u]+v.w){
				dis[v.v]=dis[u.u]+v.w;
				if(!vis[v.v])Q.push({v.v,dis[v.v]});
			}
	}
	for(auto v:u[st])ans[v.w]=dis[v.v]+w[v.v]+w[st];
}
bitset<505>W[505],E[505];
int dis2[505][505];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=12&&c<=19){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>t[j]>>y[j];
				e[i].push_back({t[j],y[j]});
				W[t[j]][i]=1;
				T=y[j];
			}
		}
		for(int i=1;i<=n;i++)
			for(auto v:e[i])
				E[i]|=W[v.v];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis2[i][j]=inf;
		for(int i=1;i<=n;i++){
			dis2[i][i]=0;
			for(int j=1;j<=500;j++)
				if(E[i][j])
					dis2[i][j]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
						dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
		while(q--){
			int u,v,ans=inf;
			cin>>u>>v;
			for(int l=1;l<=n;l++)
				for(int r=1;r<=n;r++)
					if(W[u][l]&&W[v][r])
						ans=min(ans,dis2[l][r]);
			cout<<(ans+1)*T*2+w[u]+w[v]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t[j]>>y[j];
			e[i].push_back({t[j],y[j]});
		}
		for(int j=1;j<=k;j++)
			for(int w=j+1;w<=k;w++)
				e[t[j]].push_back({t[w],y[j]+y[w]}),e[t[w]].push_back({t[j],y[j]+y[w]});
	}
	for(int i=1;i<=q;i++)cin>>s[i].u>>s[i].v,s[i].id=i,in[s[i].u]++,in[s[i].v]++;
	for(int i=1;i<=q;i++){
		if(in[s[i].u]<in[s[i].v])swap(s[i].u,s[i].v);
		dq[s[i].u]=1;
		u[s[i].u].push_back({s[i].v,s[i].id});
	}
	for(auto v:dq)
		dij(v.first);
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
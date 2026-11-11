#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[20010],top,hd[20510],dis1[1510][1510],dis2[20510];
bool flag[20510],vis[20510];
priority_queue<pair<int,int>>que;
struct node{
	int to,nxt,val;
}edge[41010];
void add(int a,int b,int c){
	edge[++top].to=b;
	edge[top].val=c;
	edge[top].nxt=hd[a];
	hd[a]=top;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(c<=11||c>=16){
			if(flag[x]){
				cout<<w[x]+w[y]+dis1[x][y]<<"\n";
				continue;
			}
			if(flag[y]){
				cout<<w[x]+w[y]+dis1[y][x]<<"\n";
				continue;
			}
			for(int i=1;i<=n+m;i++)
				dis1[x][i]=1e18,vis[i]=0;
			while(!que.empty())
				que.pop();
			dis1[x][x]=0;
			que.push({0,x});
			while(!que.empty()){
				int u=que.top().second;
				que.pop();
				if(vis[u])
					continue;
				vis[u]=1;
				for(int i=hd[u];i;i=edge[i].nxt){
					int v=edge[i].to,w=edge[i].val;
					if(dis1[x][v]>dis1[x][u]+w){
						dis1[x][v]=dis1[x][u]+w;
						que.push({-dis1[x][v],v});
					} 
				}
			}
			flag[x]=1;
			cout<<w[x]+w[y]+dis1[x][y]<<"\n";
		}
		if(c>=12&&c<=15){
			for(int i=1;i<=n+m;i++)
				dis2[i]=1e18,vis[i]=0;
			while(!que.empty())
				que.pop();
			dis2[x]=0;
			que.push({0,x});
			while(!que.empty()){
				int u=que.top().second;
				que.pop();
				if(u==y)
					break;
				if(vis[u])
					continue;
				vis[u]=1;
				for(int i=hd[u];i;i=edge[i].nxt){
					int v=edge[i].to,w=edge[i].val;
					if(dis2[v]>dis2[u]+1){
						dis2[v]=dis2[u]+1;
						que.push({-dis2[v],v});
					} 
				}
			}
			cout<<w[x]+w[y]+dis2[y]*edge[1].val<<"\n";
		}
	}
	return 0;
}

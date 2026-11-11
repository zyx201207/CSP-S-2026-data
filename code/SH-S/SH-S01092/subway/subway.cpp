#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+3;
const int inf=1e14+3;
vector<pair<int,int>> g[N];
int w[N];
int dis[N];
bool vis[N];
int tmp1[N],tmp2[N];
int c,n,m,d,q;
int read(){
	char c=getchar();
	int now=0;
	while(c>='0' and c<='9'){
		now=now*10+c-'0';
		c=getchar();
	}
	return now;
}
int x,y;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool b=true;
queue<int> pq2;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	int tb=-1;
	for(int i=1;i<=n;i++){
		x=read();
		for(int j=1;j<=x;j++){
			tmp1[j]=read(),tmp2[j]=read();
			if(tb==-1)tb=tmp2[j];
			if(tb!=tmp2[j])b=false;
		}
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				g[tmp1[j]].push_back({tmp1[k],tmp2[j]+tmp2[k]});
				g[tmp1[k]].push_back({tmp1[j],tmp2[j]+tmp2[k]});
			}
		}	
	}
	if(b==false){
		for(int i=1;i<=q;i++){
			x=read(),y=read();
			for(int j=1;j<=m;j++)dis[j]=inf,vis[j]=false;
			dis[x]=0;
			pq.push({0,x});
			while(!pq.empty()){
				int u=pq.top().second;
				pq.pop();
				if(vis[u]==true)continue;
				vis[u]=true;
				for(pair<int,int> now:g[u]){
					int v=now.first,w=now.second;
					if(dis[u]+w<dis[v]){
						dis[v]=dis[u]+w;
						pq.push({dis[v],v});
					}
				}
			}
			printf("%d\n",dis[y]+w[x]+w[y]);
		}
	}
	else{
		for(int i=1;i<=q;i++){
			x=read(),y=read();
			while(!pq2.empty())pq2.pop();
			for(int i=1;i<=m;i++)dis[i]=inf,vis[i]=false;
			pq2.push(x);
			dis[x]=0;
			bool flag=false;
			while(!pq2.empty()){
				int u=pq2.front();
				pq2.pop();
				if(vis[u])continue;
				vis[u]=true;
				for(pair<int,int> now:g[u]){
					int v=now.first,w=now.second;
					if(vis[v])continue;
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						pq2.push(v);
						if(v==y){
							flag=true;
							break;
						}
					}
				}
			}
			printf("%d\n",dis[y]+w[x]+w[y]);
		}
	}
	return 0;
}

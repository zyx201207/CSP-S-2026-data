#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=5e2+7;
set<int> s[M];
vector<pair<int,int> > g[N];
bool vis[N];
int dis[N],c,n,m,d,q,w[N],k,a,T[N];
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,x});
	while(!pq.empty()){
		auto t=pq.top();pq.pop();
		vis[t.second]=true;
		for(auto i:g[t.second]){
			if(!vis[i.first]){
				if(dis[i.first]>t.first+i.second){
					dis[i.first]=t.first+i.second;
					pq.push({dis[i.first],i.first});
				}
			}
		}
	}
}
inline int read(){
	//zheng zheng shu gu wu fu hao
	int c=getchar(),sum=0;
	while(isdigit(c)){
		sum=sum*10+(c-'0');
		c=getchar();
	}
	return sum;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read();
			T[a]=read();
			s[i].insert(a);
		}
		for(int kk=2;kk<=m;kk++){
			for(int j=1;j<kk;j++){
				if(s[i].find(kk)!=s[i].end() && s[i].find(j)!=s[i].end()){
					g[kk].push_back({j,T[kk]+T[j]});
					g[j].push_back({kk,T[kk]+T[j]});
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int x,y;
		x=read();
		y=read();
		dis[x]=0;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
}

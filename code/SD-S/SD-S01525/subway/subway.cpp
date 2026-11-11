#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10,M=505;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

int c,n,m,d,q;
int a[N],k[N];
vector<int> station[N];
vector<int> st_time[N];
vector<int> rd[N];
int T[M][N],dis[N];
int dist[1005][1005];
bool f;
void bfs(int s,int t){
	for(int i=1;i<=m;i++)dis[i]=INF;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second,d=q.top().first;
		q.pop();
		if(d>dis[u])continue;
		for(int i=0;i<station[u].size();i++){
			int road=station[u][i],t1=st_time[u][i];
//			cout<<road;
			for(int j=0;j<rd[road].size();j++){
				int v=rd[road][j],t2=T[road][v];
				if(dis[v]>dis[u]+t1+t2){
					dis[v]=dis[u]+t1+t2;
					q.push({dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	if(m<=1000)f=1;
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1,u,tm;j<=k[i];j++){
//			scanf("%d%d",&u,&tm);
			u=read(),tm=read();
			station[u].push_back(i);
			st_time[u].push_back(tm);
			rd[i].push_back(u);
			T[i][u]=tm;
		}
	}
	while(q--){
		int u,v;
//		scanf("%d%d",&u,&v);
		u=read(),v=read();
		
		if(f==1){
			if(!dist[u][v]){
				bfs(u,v);
				for(int i=1;i<=m;i++)if(i!=u)dist[u][i]=dis[i]+a[u]+a[i];
			}
			printf("%d\n",dist[u][v]);
			continue;
		}
		bfs(u,v);
		printf("%d\n",dis[v]+a[u]+a[v]);
	}
	return 0;
}


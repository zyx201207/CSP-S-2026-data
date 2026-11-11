#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int INF=1e9+7;
int read(){
	int x=0,f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
struct node{
	int u,v,next,val;
}edge[N];
struct mode{
	int v,w;
	friend bool operator<(const mode a,const mode b){
		return a.w>b.w;
	}
};
int w[N];
int dis[510][1010];
bool vis[510][1010];
int cnt,head[N];
vector<int> a[510];
int num[N];
vector<int> num2[510];
int n;
void add(int x,int y,int val){
	edge[++cnt].v=y;
	edge[cnt].u=x;
	edge[cnt].val=val;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dj(int s){
	for(int i=0;i<=1010;i++){
		dis[s][i]=INF;
	}
	int mi=INF;
	int y;
	for(int i=0;i<num[s];i++){
		if(mi>a[s][i]){
			mi=a[s][i];
			y=i+1;
		}
	}
	dis[s][n+y]=0;
	priority_queue<mode> qu;
	qu.push({n+y,dis[s][n+y]});
	while(!qu.empty()){
		mode now=qu.top();
		qu.pop();
		int x=now.v;
		if(vis[s][x]) continue;
		vis[s][x]=1;
		for(int i=head[x];~i;i=edge[i].next){
			int v=edge[i].v,w=edge[i].val;
			if(dis[s][v]>dis[s][x]+w){
				dis[s][v]=dis[s][x]+w;
				qu.push({v,dis[s][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	int c=read();
	n=read();
	int m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		num[i]=k;
		for(int j=1;j<=k;j++){
			int v=read(),val=read();
			a[i].push_back(val);
			num2[i].push_back(v);
			add(i,n+v,val);
			add(n+v,i,val);
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
	for(int i=1;i<=q;i++){
		int u=read(),v=read();
		int ans=INF;
		for(int j=1;j<=n;j++){
			if(num2[j][0]==u){
				ans=min(ans,dis[j][n+v]);
			}
		}
		cout<<w[u]+w[v]+ans<<"\n";
	}
	return 0;
}

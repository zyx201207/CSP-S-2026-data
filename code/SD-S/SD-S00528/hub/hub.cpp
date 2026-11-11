#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int c,t;
int n,k;
int cnt,head[N];
struct edge{int to,next;} edges[N];
int fa[N];
int ans;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

inline void add(int u,int v){
	edges[cnt]={v,head[u]};
	head[u]=cnt++;
	edges[cnt]={u,head[v]};
	head[v]=cnt++;
}

int find(int u){
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}

void check(int state){
	vector<bool> vis(n+5,false);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cc=k;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(state&(1<<(i-1))){
			q.push(i);
			vis[i]=1;
			for(int e=head[i];e!=-1;e=edges[e].next){
				int u=i, v=edges[e].to;
				if((~state)&(1<<(v-1)))continue;
				u=find(u);v=find(v);
				if(u!=v){
					--cc;
					fa[u]=v;
				}
			}
		}
	}
	if(cc>2)return;
	int di=-1;
	while(!q.empty()){
		int _s=q.size();
		++di;
		while(_s--){
			int u=q.front();q.pop();
			vis[u]=1;
			for(int e=head[u];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
		
	}
	ans=min(ans,di);
}

void dfs(int state,int cur){
	int cnt=__builtin_popcount(state);
	if(n-cur+cnt<k)return;
	if(cnt==k){
		check(state);
		return;
	}
	for(int i=cur+1;i<=n;i++){
		dfs(state|(1<<(i-1)),i);
	}
}

void solve(){
	ans=0x3f3f3f3f;
	dfs(0,0);
	printf("%d\n",ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(edges,0,sizeof(edges));
		n=read();k=read();
		for(int i=1;i<n;i++){
			int u,v;
			u=read();v=read();
			add(u,v);
		}
		solve();
	}
	return 0;
} 

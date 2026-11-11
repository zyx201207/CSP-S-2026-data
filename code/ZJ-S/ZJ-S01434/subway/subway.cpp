#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=502;
const int M=500005;
struct lsq{
	int v,next,val;
}xx[M<<1];
/*struct node{
	int a,b;
};
struct cmp{
	bool operator()(const node&a,const node&b)const{
		return a.a>b.a;
	} 
};priority_queue<node,vector<node>,cmp>q;*/
int a[N],ans[M+N],len[N],head[M+N];
bool vis[M+N];
int C,n,m,d,Q,cnt;
void bfs(int x){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int tt=q.front();
		q.pop();
		for(int i=head[tt];i;i=xx[i].next){
			if(ans[xx[i].v]>ans[tt]+xx[i].val){
				ans[xx[i].v]=ans[tt]+xx[i].val;
				q.push(xx[i].v);
			}
		}
	}
}
void add(int u,int v,int val){
	xx[++cnt].v=v;
	xx[cnt].next=head[u];
	xx[cnt].val=val; 
	head[u]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int u,va;
			cin>>u>>va;
			add(u,m+i,va);
			add(m+i,u,va);
		}
	}
	while(Q--){
		memset(ans,0x3f,sizeof(ans));
		memset(vis,0,sizeof(vis));
		int st,ed;
		cin>>st>>ed;
		ans[st]=0;
		bfs(st);
		cout<<ans[ed]+a[st]+a[ed]<<'\n'; 
	}
}


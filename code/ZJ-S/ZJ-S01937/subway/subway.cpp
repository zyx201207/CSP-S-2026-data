#include<bits/stdc++.h>
using namespace std;
const int N=30,M=5e5+10,Q=1e5+10;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
//题目数据
int c,n,m,d,qu;
int w[M];
//链式前向星
int head[M+N],nxt[2*M],to[2*M],lth[2*M];
int cnt;
void add(int u,int v,int l){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	lth[cnt]=l;
}
//dijkstra
bool task[M];
int lasttask;
struct Node{
	int u,L;
	bool operator<(const Node& a)const{return L>a.L;};
};
int vis[M+N];
bool lev[M+N];
void dijkstra(int s){
//	cerr<<s<<"\n";
	priority_queue<Node>q;
	memset(vis,-1,sizeof(vis));
	memset(lev,0,sizeof(lev));
	vis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		Node X=q.top();
		q.pop();
		int u=X.u,L=X.L;
		
		if(lev[u])continue;
		else lev[u]=1;
//		cerr<<u<<" "<<vis[u]<<"\n";
		if(u>n&&task[u-n])task[u-n]=0,lasttask--;
		if(lasttask==0)return;
		
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
//			cerr<<u<<"->"<<v<<"\n";
			if(vis[v]==-1||vis[v]>L+lth[i]){
				vis[v]=L+lth[i];
				q.push({v,vis[v]});
//				cerr<<"Push:"<<v<<" "<<vis[v]<<"\n";
			}
		}
	}
	return;
}


//Qst 离线处理
struct Plan{
	int u,v;
	int id,ans;
}pl[Q];
bool cmp1(Plan x,Plan y){
	return x.u<y.u;
}
bool cmp2(Plan x,Plan y){
	return x.id<y.id;
}


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),qu=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			add(i,a+n,t);
			add(a+n,i,t);
		}
	}
	for(int i=1;i<=qu;i++){
		int u=read(),v=read();
		if(u>v)swap(u,v);
		pl[i]={u,v,i,-1};
	}
	sort(pl+1,pl+qu+1,cmp1);
	for(int i=1;i<=qu;){
		int j=i;
		memset(task,0,sizeof(task));
		while(pl[j].u==pl[i].u){
			if(task[pl[j].v]==0){
				task[pl[j].v]=1;
				lasttask++;	
			}
			j++;
		}
		dijkstra(pl[i].u+n);
		while(i<j){
			pl[i].ans=vis[pl[i].v+n];
			i++;
		}
	}
	sort(pl+1,pl+qu+1,cmp2);
	for(int i=1;i<=qu;i++){
		printf("%d\n",pl[i].ans+w[pl[i].u]+w[pl[i].v]);
	}
	return 0;
}
//16:16 暴力过了小样例（44pts
//16:57 摆了 阿米诺斯
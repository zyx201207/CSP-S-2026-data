#include<bits/stdc++.h>
using namespace std;
const int maxa=2e6+10;
long long a[maxa];
int n,d,c,t;
int dfn[maxa],dfnt[maxa];
int head[maxa];
struct Edge{
	int next,w,to;
}e[maxa];
int k=0;
void adde(int x,int y){
	e[++k].to=y;
	e[k].w=abs(a[x]-a[y]);
	e[k].next=head[x];
	head[x]=k;
} 
bool book[maxa];
struct node{
	int id,w;bool flag;
	bool operator<(const node&a)const{
		return w>a.w;
	}
};
priority_queue<node> q;
void dijkstra(){
	memset(dfn,0x3f3f3f3f,sizeof(dfn));
	memset(dfnt,0x3f3f3f3f,sizeof(dfnt));
	while(!q.empty())q.pop();
	node qt;
	qt.id=1;qt.w=0;
	
	q.push(qt);
	while(!q.empty()){
		qt=q.top();q.pop();
		int w=qt.w;int id=qt.id;
		if(book[id])continue;
		book[id]=1;
		for(int i=head[id];i>0;i=e[i].next){
			int uw=e[i].w;
			int uid=e[i].to;
			if(dfn[uid]>uw+dfn[id]){
				dfnt[uid]=dfn[uid];
				dfn[uid]=dfn[id]+uw;
				qt.id=uid;qt.w=dfn[id];
				q.push(qt);
			}else if(dfnt[uid]>uw+w){
				dfnt[uid]=uw+w;
				qt.id=uid;qt.w=dfnt[uid];
				q.push(qt);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(	;t>0;t--){
		memset(a,0,sizeof(a));
		memset(head,0,sizeof(head));
		k=0;
		memset(e,0,sizeof(e));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]-a[j]>d)continue;
				adde(i,j);
				adde(j,i);
			}
		} 
		dijkstra();
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dfn[i]==dfnt[i])ans++;
		} 
		cout<<ans<<endl;
	}
	return 0;
}
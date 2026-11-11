#include<bits/stdc++.h>
#define ll long long
const int MAXM=500010,MAXN=510;
using namespace std;
ll n,m,q,c,d,w[MAXN],dislc[MAXN][MAXN][2],disa[MAXN+10],a[MAXM][30],t[MAXM][30];
int k[MAXN],cn[MAXM];
struct edge{
	int v,nxt;
	long long w;
}e[MAXN*MAXN+40];
int head[MAXN+10],cnt;
void add_edge(int u,int v,ll w){
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void yuchul(){
	memset(dislc,-1,sizeof(dislc));
	for(int i=1;i<=n;i++){
		dislc[i][i][0]=0;
	}
	for(int i=1;i<=m;i++){
		for(int jk=1;jk<=cn[i];jk++){
			for(int lk=1;lk<=cn[i];lk++){
				int j=a[i][jk];
				int l=a[i][lk];
				if(j==l||j==0||l==0) continue; 
				if(dislc[j][l][0]==-1) dislc[j][l][0]=t[i][jk]+t[i][lk];
				dislc[j][l][0]=min(t[i][jk]+t[i][lk],dislc[j][l][0]);
			}
		}
	}
}
void min_dis_lc(){
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==l||j==l||i==j) continue;
				if(dislc[i][l][0]==-1||dislc[l][j][0]==-1) continue;
				if(dislc[i][j][0]>dislc[i][l][0]+dislc[l][j][0]||dislc[i][j][0]==-1){
					dislc[i][j][0]=dislc[i][l][0]+dislc[l][j][0];
					dislc[i][j][1]=1;
				} 
			}
		}
	}
}
struct node{
	ll dis;
	int v;
	bool operator<(const node& a)const{
		return dis<a.dis;
	}	
};
priority_queue<node> que;
bool vis[MAXN+10];
void dij(int s){
	memset(disa,-1,sizeof(disa));
	que.push({0,s});
	disa[s]=0;
	while(!que.empty()){
		node x=que.top();
		que.pop();
		ll disx=x.dis,u=x.v;
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(disa[v]>disx+w||disa[v]==-1){
				disa[v]=disx+w;
				que.push({disa[v],v});
			}
		}		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a_i,t_i;
			cin>>a_i>>t_i;
			a[a_i][++cn[a_i]]=i;
			t[a_i][cn[a_i]]=t_i;
		}
	}
	yuchul();
	min_dis_lc();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j!=l){
					if(dislc[j][l][1]!=1&&dislc[l][j][1]!=1&&dislc[j][l][0]!=-1){
						add_edge(j,l,dislc[l][j][0]);
					}
				}
			}
		}
		for(int j=1;j<=cn[x];j++){
			add_edge(n+1,a[x][j],t[x][j]);
			add_edge(a[x][j],n+1,t[x][j]);
		}
		for(int j=1;j<=cn[y];j++){
			add_edge(n+2,a[y][j],t[y][j]);
			add_edge(a[y][j],n+2,t[y][j]);
		}
		dij(n+1);
		cout<<disa[n+2]+w[x]+w[y]<<endl;		
	}
	return 0;
}


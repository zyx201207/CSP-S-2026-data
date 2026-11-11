#include <bits/stdc++.h>
using namespace std;
#define il inline
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char ibuf[LEN],obuf[LEN],tbuf[20],*p1=ibuf,*p2=ibuf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(int &x){
		char ch=gc();x=0;
		while(ch< '0'||ch> '9')ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
	il void read(int &x,auto &...y){read(x),read(y...);}
	il void write(int x){
		short top=0;
		do tbuf[top++]=x%10;while(x/=10);
		while(top)pc(tbuf[--top]|48);
		pc('\n');
	}
}
using namespace FastIO;

const int N=1e6+5,M=2e6+5;

int n,m,k,u,v,ans;

int cnt,head[N];
struct Edge{int nxt,v;}e[M];
il void AddEdge(int u,int v){
	e[++cnt]={head[u],v},head[u]=cnt;
	e[++cnt]={head[v],u},head[v]=cnt;
}

int tot[2][N],dis[N],faz[N],mxd[N];
bool vis[N];
il int Bfs(int S,int ban){
	int tmp=0;
	for(int u=1;u<=n;u++)dis[u]=N,faz[u]=0;
	queue<int>q;
	dis[S]=0,q.push(S);
	for(int u;!q.empty();){
		u=q.front(),q.pop();
		for(int i=head[u],v;i;i=e[i].nxt){
			if((i>>1)==ban)continue;
			if(v=e[i].v,dis[v]==N){
				dis[v]=dis[u]+1;
				faz[v]=u,q.push(v);
			}
		}
		vis[u]=1,tmp=u;
	}
	return tmp;
}
il void Dfs(int u,int f,int ban){
	for(int i=head[u],v;i;i=e[i].nxt){
		if( (i>>1)==ban )continue;
		if(v=e[i].v,v==f)continue;
		Dfs(v,u,ban);
		mxd[u]=max(mxd[u],mxd[v]+1);
	}
	tot[m][mxd[u]]++;
}
il void Solve(int ban){
	for(int i=0;i< m;i++){
		for(int r=0;r<=n;r++){
			tot[i][r]=0;
		}
	}
	m=0;
	for(int u=1;u<=n;u++)mxd[u]=0,vis[u]=0;
	for(int u=1;u<=n;u++){
		if(vis[u])continue;
		int S=Bfs(u,ban),T=Bfs(S,ban),p;
		for(p=T;(dis[p]<<1)>dis[T];p=faz[p]);
		Dfs(p,0,ban),m++;
	}
	for(int i=0;i<m;i++){
		for(int r=n-1;r>=0;r--){
			tot[i][r]+=tot[i][r+1];
		}
		for(int r=n-0;r>=0;r--){
			tot[i][r]+=tot[i][r]==0;
		}
	}
	if(m==1){
		for(int r=0;r<=n;r++){
			if(tot[0][r]<=k){
				ans=min(ans,r);
				return ;
			}
		}
	}
	for(int l=0,r=n;l<=n;l++){
		if(tot[0][l]+tot[1][r]>k)continue;
		while(r>=0&&tot[0][l]+tot[1][r]<=k)r--;
		ans=min(ans,max(l,r+1));
	}
}

il void Run(){
	read(n,k),ans=n,cnt=1;
	for(int u=1;u<=n;u++)head[u]=0;
	for(int i=1;i< n;i++)read(u,v),AddEdge(u,v);
	for(int i=0;i< n;i++)Solve(i);
	write(ans);
}

int o,t;
il void main(){
	freopen("hub.in" ,"r",stdin );
	freopen("hub.out","w",stdout);
	for(read(o,t);t;t--)Run();
}}
int main(){DYC::main(),DYC::flush();}

#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1000010,D=21;
long long n,m,dis[M],d,t[M],sum,b[N],lst,ans,ppppp,en,q;
int h[M*D],cnt1;
struct Edge{
	int to,w,next;
}edge[M*D];
bool vis[D][M];
void add(int u,int v,int w){
	edge[++cnt1]=Edge{v,w,h[u]};
	h[u]=cnt1;
}
long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
void dfs(int u,int fa,long long res){
	if(res>=ans){
		return;
	}
	if(u==en){
		ans=res;
		return;
	}
    for(int i=h[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u,res+edge[i].w);
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ppppp=read();
	n=read();
	m=read();
	d=read();
	q=read();
	ans=0;
	for(int i=1;i<=m;i++){
		t[i]=read();
	}
	for(int i=1;i<=n;i++){
		long long opt,oq,oq1;
		opt=read();
		oq=read();
		oq1=read();
		
		for(int j=2;j<=opt;j++){
			long long id,w;
			id=read();
			w=read();
			add(oq,id,w+oq1);
			
		}
	}
	for(int i=1;i<=q;i++){
		int u;
		u=read();
		en=read();
		dfs(u,0,0);
		write(t[u]+ans+t[en]);
	}
	

    return 0;
}

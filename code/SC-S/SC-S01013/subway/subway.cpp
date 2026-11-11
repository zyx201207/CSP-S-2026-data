#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,op,tot,cnt,u,t,ans;
const int N=505,M=5e5+505+5;
int w[M],vis[M];
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
struct node{
	int v,t;
};
vector<node> b[M];
void solve(int fa,int x,int y,int p){
	if(p>=ans) return ;
	vis[x]=1;
	if(x==y){
		ans=min(ans,p);
		return ;
	}
	for(node it:b[x]){
		if(it.v!=fa&&vis[it.v]==0) solve(x,it.v,y,p+it.t);
		vis[it.v]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	tot=m;
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		op=read();
		++tot;
		for(int j=1;j<=op;j++) {
			u=read();t=read();
			b[u].push_back({tot,t});
			b[tot].push_back({u,t});
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof 0);
		ans=1e9;
		int st,ed;
		st=read();ed=read();
		solve(0,st,ed,0);
		cout<<ans+w[st]+w[ed]<<endl;
	}
	return 0;
}
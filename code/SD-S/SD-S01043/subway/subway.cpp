#include<bits/stdc++.h>
using namespace std;
const int M=500005,N=1005;
int c,n,m,d,q,w[M],p,g[M];
long long f[N][N],ans,e[M];
int tot,ver[M],nxt[M],hed[M];
void add(int x,int y,int z){
	ver[++tot]=y;
	nxt[tot]=hed[x];
	e[tot]=z;
	hed[x]=tot;
}
int read(){
	char tt;
	tt=getchar();
	while(tt<'0'||tt>'9'){
		tt=getchar();
	}
	int pp=tt-'0';
	tt=getchar();
	while(tt>='0'&&tt<='9'){
		pp=pp*10+(tt-'0');
		tt=getchar();
	}
	return pp;
}
int main(){
	//ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e10;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		p=read();
		int x,z;
		for(int j=1;j<=p;j++){
			x=read(),z=read();
			g[x]++;
			add(x,i,z);
		}
	}
	long long he;
	for(int i=1;i<=m;i++){
		for(int j=1,u=hed[i];j<=g[i];j++,u=nxt[u]){
			for(int k=1,v=hed[i];k<=g[i];k++,v=nxt[v]){
				if(j>=k){
					continue;
				}
				int uu=ver[u],vv=ver[v];
				he=e[u]+e[v];
				if(f[uu][vv]==1e10){
					f[vv][uu]=f[uu][vv]=he;
				}
				else{
					f[vv][uu]=f[uu][vv]=min(f[uu][vv],he);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		x=read(),y=read();
		ans=1e15;
		for(int i=1,u=hed[x];i<=g[x];i++,u=nxt[u]){
			for(int j=1,v=hed[y];j<=g[y];j++,v=nxt[v]){
				ans=min(ans,e[u]+e[v]+f[ver[u]][ver[v]]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

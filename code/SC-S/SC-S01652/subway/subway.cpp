#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N=5e5+5,mod=998244353;
const ll inf=1LL<<60;

inline int read(){ 
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return w*s;
}

struct Info{
	int id,Tim;
}p[N][22];
int c,n,m,d,q,w[N],k,a,t,S,T;
int tot[N];
ll dis[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read(),t=read();
			p[a][++tot[a]].id=i;
			p[a][tot[a]].Tim=t;
		}
	}
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				int x=p[i][j].id,y=p[i][k].id;
				if(1LL*p[i][j].Tim+1LL*p[i][k].Tim<dis[x][y]){
					dis[x][y]=1LL*p[i][j].Tim+1LL*p[i][k].Tim;
				}
				if(1LL*p[i][j].Tim+1LL*p[i][k].Tim<dis[y][x]){
					dis[y][x]=1LL*p[i][j].Tim+1LL*p[i][k].Tim;
				}					
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]<inf&&dis[k][j]<inf){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}				
				}
			}
		}
	}
	while(q--){
		S=read(),T=read();
		ll minv=inf;
		for(int i=1;i<=tot[S];i++){
			for(int j=1;j<=tot[T];j++){
				int x=p[S][i].id,y=p[T][j].id;
				if(dis[x][y]<inf){
					if(dis[x][y]+1LL*p[S][i].Tim+1LL*p[T][j].Tim<minv){
						minv=dis[x][y]+1LL*p[S][i].Tim+1LL*p[T][j].Tim;
					}
				}
			}
		}
		printf("%lld\n",minv+1LL*w[S]+1LL*w[T]);
	}
	return 0;
}
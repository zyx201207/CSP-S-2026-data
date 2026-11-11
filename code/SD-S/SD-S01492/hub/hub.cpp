#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T>inline void read(T &x){
	bool f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?-x:x);return;
} 
//template<typename T,typename ...Args>inline void read(T &x,Args &...x_){
//	read(x),read(x_...);
//}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');return;
}
const int N=1e2+10;
int n,block;
struct node{int u,v;}e[N];
int dis[N][N],fa[N],num[N];
inline int finds(int x){
	if(fa[x]==x) return x;
	return fa[x]=finds(fa[x]);
}
inline void unions(int x,int y){
	x=finds(x),y=finds(y);
	if(x==y) return;
	block=~-block; 
	num[y]+=num[x],fa[x]=y;  
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	register int i,j,k,C,T,K,cnt;
	read(C);read(T);
	while(T--){
		read(n);read(K);
		register int rec=n+1; 
		for(i=1;i<=n;i=-~i)for(j=1;j<=n;j=-~j)dis[i][j]=1e8;
		for(i=1;i<=n;i=-~i) fa[i]=i,num[i]=1,dis[i][i]=0;
		for(i=1;i<n;i=-~i){
			register int u,v;
			read(u);read(v);
			e[i]=(node){u,v};
			dis[u][v]=1;dis[v][u]=1;
		}
		for(k=1;k<=n;k=-~k)for(i=1;i<=n;i=-~i)for(j=1;j<=n;j=-~j){
			if(i==j)continue;
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
		for(k=1;k<=(1<<n)-1;k=-~k){
			for(j=1,cnt=0;j<=n;j=-~j) if((k>>(j-1))&1) cnt=-~cnt;
			if(cnt!=K) continue;
			for(i=1;i<=n;i=-~i) fa[i]=i,num[i]=1;block=cnt;
			for(i=1;i<n;i=-~i){
				register int u=e[i].u,v=e[i].v;
				if(((k>>(u-1))&1)&&((k>>(v-1))&1)) unions(u,v);
			}
			if(block>2)continue;
			register int ans=0;
			for(i=1;i<=n;i=-~i){
				register int rsc=1e8;
				for(j=1;j<=n;j=-~j){
					if((k>>(j-1))&1){
						rsc=min(rsc,dis[i][j]);
					}
				}
				if(rsc!=1e8) ans=max(ans,rsc);
			}
			rec=min(rec,ans);
		} 
		write(rec),putchar('\n');
	}
	return 0;
}

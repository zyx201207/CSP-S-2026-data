#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int N=505,M=5e5+5,inf=1e18;
int cid,n,m,d,q;
int w[M];
struct node{
	int id,t;
};
vector<node> e[M];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),y=read();
			e[x].push_back((node){i,y});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto p:e[i])
			for(auto q:e[i])
				f[p.id][q.id]=min(f[p.id][q.id],p.t+q.t);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	while(q--){
		int u=read(),v=read(),ans=inf;
		for(auto p:e[u])
			for(auto q:e[v])
				ans=min(ans,w[u]+p.t+f[p.id][q.id]+q.t+w[v]);
		print(ans,'\n');
	}
	return 0;
}
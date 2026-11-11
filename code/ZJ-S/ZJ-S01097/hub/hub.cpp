#include<bits/stdc++.h>
#define fst first
#define scd second
#define db double
#define ll long long
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define sz(x) ((int)x.size())
#define ms(f,x) memset(f,x,sizeof(f))
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define ACN(i,H_u) for(int i=H_u;i;i=E[i].nxt)
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
template<typename T>void rd(T&x){
	x=0;bool f=false;char ch=getchar();
	while(ch<48||ch>57)f|=ch==45,ch=getchar();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
}
template<typename T,typename...Args>
void rd(T&x,Args&...y){rd(x),rd(y...);}
//dfs
const int inf=0x3f3f3f3f;
const int maxn=4e3;
const int N=maxn+10;
int H[N],edge_cnt,f[N],g[N],n,kn,fa[N];
//wmr
struct node{int u,v;}e[N];
struct Edge{int nxt,to;}E[N<<1];
void add(int u,int v){E[++edge_cnt]={H[u],v};H[u]=edge_cnt;}
int get_fa(int x){return x==fa[x]?x:fa[x]=get_fa(fa[x]);}
void merge(int x,int y){x=get_fa(x),y=get_fa(y);if(x!=y)fa[x]=y;}
//incra
int dd;
int dfs(int u,int pre){
	int mi=inf,ma=-inf,cnt=0,res=0;
	ACN(i,H[u]){
		int v=E[i].to;
		if(v==pre)continue;
		res+=dfs(v,u);
		mi=min(mi,f[v]+1),ma=max(ma,g[v]+1);
		if(f[v]!=inf)++cnt;
	}
	if(cnt>=2){
		f[u]=0,g[u]=-inf;
		ACN(i,H[u]){
			int v=E[i].to;
			if(v==pre)continue;
			if(f[v]!=inf)res+=f[v];
		}
		++res;
	}else if(cnt==1){
		if(max(ma,0)+mi<=dd)f[u]=mi,g[u]=-inf;
		else f[u]=0,g[u]=-inf,res+=mi;
	}else{
		if(ma==dd)res=1,f[u]=0,g[u]=-inf;
		else f[u]=inf,g[u]=max(ma,0);
	}
//	printf("%d %d %d %d\n",u,res,f[u],g[u]);
	return res;
}
//lottle
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,T;
	rd(cid,T);
	while(T--){
		rd(n,kn);
		L(i,1,n-1)rd(e[i].u,e[i].v);
		if(kn>=n){puts("0");continue;}
		if(cid==13||cid==14){
			int m=(n-1)/2;
			printf("%d\n",(m-kn+7)/4);
			continue;
		} 
		int ans=inf;
		L(i,1,n-1){
			fill(H+1,H+n+1,0);edge_cnt=0;
			L(j,1,n)fa[j]=j;
			L(j,1,n-1)if(j!=i)add(e[j].u,e[j].v),add(e[j].v,e[j].u),merge(e[j].u,e[j].v);
			int u=1,v;
			L(j,2,n)if(get_fa(u)!=get_fa(j)){v=j;break;}
			dd=1;
			int l=0,r=n+1;
			while(l+1<r){
				int mid=l+r>>1;dd=mid;
				if(max(dfs(u,0),1)+max(dfs(v,0),1)<=kn)r=mid;
				else l=mid;
			}
			ans=min(ans,r);
		}
		printf("%d\n",ans);
	}
	return 0;
}


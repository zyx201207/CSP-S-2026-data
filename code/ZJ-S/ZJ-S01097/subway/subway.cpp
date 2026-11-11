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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=500,maxm=5e5;
const int N=maxn+10,M=maxm+10;
int cid,n,m,dn,qn,w[M];ll dis[N][N];
//wmr
struct node{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
};
vector<node>a[M];
//incra

//lottle
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rd(cid,n,m,dn,qn);
	L(i,1,m)rd(w[i]);
	L(i,1,n){
		int kn;rd(kn);
		while(kn--){
			int x,y;rd(x,y);
			a[x].eb(node(i,y));
		}
	}
	ms(dis,0x3f);
	L(i,1,n)dis[i][i]=0;
	L(i,1,m){
		int t=sz(a[i]);
		L(j,0,t-1)L(k,j+1,t-1){
			node p=a[i][j],q=a[i][k];
			dis[p.x][q.x]=dis[q.x][p.x]=min(dis[p.x][q.x],(ll)p.y+q.y);
		}
	}
	L(k,1,n)L(i,1,n)L(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(qn--){
		int x,y;rd(x,y);
		ll ans=INF;
		for(node p:a[x])for(node q:a[y])ans=min(ans,dis[p.x][q.x]+p.y+q.y);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}

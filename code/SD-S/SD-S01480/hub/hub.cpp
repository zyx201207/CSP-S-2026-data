// 华风夏韵，洛水天依！

/*
千山踏遍更愿你柔软

唱太阳 唱太阳 唱太阳 唱太阳 


束花线 自灵魂空缺
圈起叶茂枝繁 何以拼凑“眷恋”
是斑驳画板 是皱褶谱页 
是热爱的呼喊 
我逃开一切 蜚语和流言
拥入这片蓝 幸福已然真切 
从不愿说永远 永远太空泛
只清唱你我两端 此刻的璀璨 
*/

#include<bits/stdc++.h>

//#define int long long
//#define double long double
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define multitest 1

using namespace std;
bool mem_beg;

const int N=100+5,M=6e5+5,V=6e5+5,mod=998244353;
const int dx[10]={0,1,-1,0,0,1,1,-1,-1},dy[10]={0,0,0,1,-1,1,-1,1,-1};
const double eps=1e-9;

il void read(int &x){char c;while((c=getchar())<'0'||c>'9');x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);}
il void chmin(int &a,const int b){b<a&&(a=b);}

int __T=1,test_id;

int n,k,dis[N][N];
bitset <N> ch;
vector <int> p[N];

struct _dsu
{
	int fa[N],rk[N];
	il void init(int n){rep(i,0,n+1) fa[i]=i,rk[i]=1;}
	il int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
	il bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		rk[x]==rk[y]?(fa[y]=x,++rk[x]):(rk[x]>rk[y]?(fa[y]=x):(fa[x]=y));
		return 1;
	}
} dsu;

il void floyd()
{
	rep(k,1,n) rep(i,1,n) rep(j,1,n) chmin(dis[i][j],dis[i][k]+dis[k][j]);
}
il int popc(int x){int ans=0;while(x)x&1&&++ans,x>>=1;return ans;}

il void Solve()
{
	read(n),read(k);
	{int u,v; rep(i,1,n-1) read(u),read(v),p[u].pb(v),p[v].pb(u),dis[u][v]=dis[v][u]=1;}
	
	rep(i,1,n) dis[i][i]=1;
	floyd();
	
	int u,sz,tot,ans=1e9,now,tmp;
	rep(s,1,(1<<n)-1) if(popc(s)>1)
	{
		dsu.init(n);
		rep(i,0,n+1) ch[i]=0;
		tot=0;
		rep(i,0,n-1) if(s>>i&1)
		{
			u=i+1,sz=p[u].size(),++tot;
			rep(j,0,sz-1) ch[p[u][j]]&&(dsu.merge(u,p[u][j])&&--tot);
		}
		if(tot^2) continue;
		
		tmp=0;
		rep(i,0,n-1) if(!(s>>i&1))
		{
			u=i+1,now=1e9;
			rep(j,0,n-1) if(s>>j&1) now=min(now,dis[u][j+1]);
			tmp=max(tmp,now);
		}
		ans=min(ans,tmp);
	}
	
	printf("%d\n",ans);
}

il void Init()
{
	read(test_id);
}

il void Clear()
{
	rep(i,0,n+1) p[i].clear();
	n=k=0;
}

bool mem_end;
signed main()
{
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"Memory = %.3lf MB\n\n",abs(&mem_beg-&mem_end)/1024./1024.);
	Init(),multitest&&(read(__T),1);
	rep(__Ti,1,__T) Solve(),__Ti!=__T&&(Clear(),1);
//	fprintf(stderr,"\nTime = %.3lf ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

/*
n<=10 | 1~3 15pts | O(n^3)-O(2^n*n^2) 暴力，先floyd一下 
n<=1000 k<=2 | 7 5pts | O(n^2) 枚举选1个点，另一个换根dp
? 性质A | 13,14 10pts | O(n) 也许可以贪心 
*/


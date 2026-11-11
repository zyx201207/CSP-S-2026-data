#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace io{
	int read(){
		int x=0,y=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') y=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		return x*y;
	}
	void output(int x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9) output(x/10);
		putchar(x%10|48);
	}
}
#define read() io::read()
#define output(x) io::output(x)
namespace Czming__{
	struct graph{
		int first[1000001],nxd[2000001],to[2000001],cnt;
		void clr(int siz){
			cnt=0;
			for(int i=1;i<=siz;i++) first[i]=0;
		}	
		void add(int u,int v,bool flag){
			to[++cnt]=v;
			nxd[cnt]=first[u];
			first[u]=cnt;
			if(flag) add(v,u,false);
		}
	}g;
	int l,r,mid,answer,n,k,father[100001],sums,flag[100001],ma,ans[100001],cnt,u[100001],v[100001],aa[100001];
	bool fl;
	void init(){return ;}
	int finds(int x){
		if(father[x]==x) return x;
		return father[x]=finds(father[x]);
	}
	void merge(int x,int y){
		x=finds(x);
		y=finds(y);
		if(x==y) return ;
		father[x]=y;
	}
	void dfs(int x,int fa,int dep){
		if(flag[x]){
			ma=max(ma,dep);
			fl=true;
			return ;
		}
		for(int i=g.first[x],to;i;i=g.nxd[i]){
			to=g.to[i];
			if(to==fa) continue;
			dfs(to,x,dep+1);
			if(fl) break;
		}
	}
	void dfs2(int x,int fa){
		int ma1=0,ma2=0;
		for(int i=g.first[x],to;i;i=g.nxd[i]){
			to=g.to[i];
			if(to==fa) continue;
			dfs2(to,x);
			if(ma1<aa[to]){
				ma2=ma1;
				ma1=aa[to];
			}
			else if(ma2<aa[to]) ma2=aa[to];
		}
		if(ma1+ma2+2>mid){
			sums++;
			aa[x]=0;
		}
		else aa[x]=max(ma1,ma2)+1;
	}
	void work(int id){
		n=read();
		k=read();
		g.clr(n);
		for(int i=1;i<n;i++){
			u[i]=read();
			v[i]=read();
			g.add(u[i],v[i],true);
		}
		if(id<=3){
			answer=1e18;
			for(int i=1;i<(1<<n);i++){
				if(__builtin_popcount(i)!=k) continue;
				for(int j=1;j<=n;j++){
					father[j]=j;
					flag[j]=((i>>(j-1))&1);
				}
				for(int i=1;i<n;i++){
					if(flag[u[i]]&&flag[v[i]]) merge(u[i],v[i]);
				}
				cnt=0;
				for(int i=1;i<=n;i++){
					if(flag[i]) ans[++cnt]=finds(i);
				}
				sums=0;
				sort(ans+1,ans+cnt+1);
				for(int i=1;i<=cnt;i++){
					if(i==1||ans[i]!=ans[i-1]) sums++;
				}
				if(sums<=2){
					ma=0;
					for(int i=1;i<=n;i++){
						fl=false;
						dfs(i,0,0);
					}
					answer=min(answer,ma);
				}
			}
			output(answer);
			puts("");
			return ;
		}
		if(id==13||id==14){
			int m=n/2;
			if(k==n){
				puts("0");
				return ;
			}
			if(k>=m){
				puts("1");
				return ;
			}
			for(int i=1;i<=m;i++){
				if(k+i*4>=m){
					output(i+1);
					puts("");
					return ;
				}
			}
		}
		return ;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id=read(),T=read();
	Czming__::init();
	while(T--) Czming__::work(id);
	return 0;
}

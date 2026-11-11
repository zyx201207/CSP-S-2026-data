#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
const ll inf=1e17+7;
const int N=2e6+5;
const int mod=998244353;
int tid,n,nx[N],pre[N],lp[N],rp[N],ls[N],rs[N];
ll d,a[N];
inline int qpre(int l,int r,int x){
	int pl=max(lp[x],l),pr=min(rp[x],r);
	return max(0,pr-pl+1);
}
inline int qnx(int l,int r,int x){
	int pl=max(ls[x],l),pr=min(rs[x],r);
	return max(0,pr-pl+1);
}
int f[N],g[N];
bool bjf[N],bjg[N];
int qf(int x){
	if(bjf[x]) return f[x];
	if(pre[x]==x) return 0;
	int p=pre[x];
	f[x]=qnx(p,x-1,x);
	if(nx[p]==x) f[x]+=qf(p);
	bjf[x]=1;
	return f[x];
}
int qg(int x){
	if(bjg[x]) return g[x];
	if(nx[x]==x) return 0;
	int p=nx[x];
	g[x]=qpre(x+1,p,x);
	if(pre[p]==x) g[x]+=qg(p);
	bjg[x]=1;
	return g[x];
}
void sol(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) lp[i]=ls[i]=n+1,rp[i]=rs[i]=0;
	pre[1]=1,nx[n]=n;
	for(int i=1,pos=1;i<n;i++){
		while(pos<n&&a[pos+1]<=a[i]+d) pos++;
		nx[i]=pos;
		ls[pos]=min(ls[pos],i);
		rs[pos]=max(rs[pos],i);
	}
	for(int i=2,pos=1;i<=n;i++){
		while(pos<=n&&a[pos]<a[i]-d) pos++;
		pre[i]=pos;
		lp[pos]=min(lp[pos],i);
		rp[pos]=max(rp[pos],i);
	}
	for(int i=1;i<=n;i++) bjf[i]=bjg[i]=0;
	ll ans=0;
	for(int i=1;i<n;i++){
		int u=i,v=i+1,lt=0,rt=0;
		if(pre[u]!=u){
			int p=pre[u];
			lt+=qnx(p,u-1,v);
			if(nx[p]==v) lt+=qf(p); 
		}
		if(nx[v]!=v){
			int p=nx[v];
			rt+=qpre(v+1,p,u);
			if(pre[p]==u) rt+=qg(p);
		}
		//printf("i:%d %d %d\n",i,lt,rt);
		ans+=1ll*lt*rt;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	scanf("%d%d",&tid,&T);
	while(T--) sol();
	return 0;
}
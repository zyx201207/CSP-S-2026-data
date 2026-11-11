#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll in(){
	ll x=0,t=1;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')t=-t;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*t;
}
inline void out(ll x){
	if(x<0)putchar('-'),x=-x;
	char stk[30];ll top=0;
	do{stk[++top]=(x%10)^48;x/=10;}while(x>0);
	while(top)putchar(stk[top--]);
}

const ll zj=5e5+10,inf=LONG_LONG_MAX>>1;
ll c,n,m,d,q,w[zj],kk;
ll a,t;
ll ans=inf;
//注意内存
struct node{
	ll lx,tt;
};
vector<node> zd[zj];//存贮经过这个站点的所有路线 
ll f[520][520];

inline ll minn(ll x,ll y){
	if(x<y)return x;
	return y;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),q=in();
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			f[i][j]=inf;
	for(ll i=1;i<=n;++i)f[i][i]=0;
	for(ll i=1;i<=m;++i)w[i]=in();
	for(ll i=1;i<=n;++i){
		kk=in();
		for(ll j=1;j<=kk;++j){
			//a[i][j],t[i][j];
			a=in();
			t=in();
			ll siz=zd[a].size();
			for(ll k=0;k<siz;++k)f[i][zd[a][k].lx]=f[zd[a][k].lx][i]=t+zd[a][k].tt;
			zd[a].push_back({i,t});
		}
	}
//	****************************************建边
	for(ll k=1;k<=n;++k){
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	ll u,v;
	for(ll o=1;o<=q;++o){
		u=in(),v=in();
		ans=inf;
		ll si1=zd[u].size(),si2=zd[v].size(),ut,vt;
		for(ll i=0;i<si1;++i){
			for(ll j=0;j<si2;++j){
				ll ii=zd[u][i].lx;
				ll jj=zd[v][j].lx;
				if(ans>f[ii][jj]){
					ans=f[ii][jj];
					ut=zd[u][i].tt;
					vt=zd[v][j].tt;
				}
			}
		}
//		prllf("wu:%lld ut:%lld vt:%lld wv:%lld",w[u],ut,vt,w[v]);
		out(ans+w[u]+w[v]+ut+vt);
		puts("");
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
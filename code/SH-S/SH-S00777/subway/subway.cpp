#include<bits/stdc++.h>
#define N 500001
#define M 501
#define INF 1e18
using namespace std;
typedef long long ll;
ll n,m,d,nQ,w[N],len[M],nV,f[M][M];
vector<ll> a[M],t[M],rlw[N],rlt[N];
void read(ll &x){
	x=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}
void write(ll x){
	if(x<10) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
void input(){
//	scanf("%lld %lld %lld %lld",&m,&n,&d,&nQ);
//	for(ll i=1;i<=n;i++) scanf("%lld",&w[i]);
	read(m); read(n); read(d); read(nQ);
	for(ll i=1;i<=n;i++) read(w[i]);
	for(ll i=1;i<=m;i++){
//		scanf("%lld",&len[i]); ll va,vt;
		read(len[i]); ll va,vt;
		for(ll j=1;j<=len[i];j++){
			read(va); read(vt);
			a[i].push_back(va);
			t[i].push_back(vt);
			rlw[va].push_back(i);
			rlt[va].push_back(vt);
		}
	}
}
void solveBF(){
	nV=m+n;
	for(ll i=1;i<=nV;i++)
		for(ll j=1;j<=nV;j++)
			if(i==j) f[i][j]=0;
			else f[i][j]=INF;
	for(ll i=1;i<=m;i++)
		for(ll j=0;j<len[i];j++){
			ll va=a[i][j],vt=t[i][j];
			f[va][n+i]=f[n+i][va]=vt;
		}
	for(ll k=1;k<=nV;k++)
		for(ll u=1;u<=nV;u++)
			for(ll v=1;v<=nV;v++) f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
	for(ll i=1;i<=nQ;i++){
		ll S,T; scanf("%lld %lld",&S,&T);
		printf("%lld\n",f[S][T]+w[S]+w[T]);
	}
}
void solve(){
//	for(ll i=1;i<=n;i++) printf("%lld\n",rlw[i].size());
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=m;j++)
			if(i==j) f[i][j]=0;
			else f[i][j]=INF;
	for(ll u=1;u<=n;u++)
		for(ll i=0;i<rlw[u].size();i++)
			for(ll j=i+1;j<rlw[u].size();j++){
				ll u1=rlw[u][i],u2=rlw[u][j],w=rlt[u][i]+rlt[u][j];
				f[u1][u2]=f[u2][u1]=min(f[u2][u1],w);
			}
	for(ll k=1;k<=m;k++)
		for(ll u=1;u<=m;u++)
			for(ll v=1;v<=m;v++) f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
	for(ll i=1;i<=nQ;i++){
//		ll S,T; scanf("%lld %lld",&S,&T);
		ll S,T; read(S); read(T);
		ll ans=INF;
		for(ll j=0;j<rlw[S].size();j++)
			for(ll k=0;k<rlw[T].size();k++){
				ll u=rlw[S][j],v=rlw[T][k];
				ans=min(ans,f[u][v]+rlt[S][j]+rlt[T][k]+w[S]+w[T]);
			} 
		write(ans); putchar('\n');
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	T=1;
	for(ll t=1;t<=T;t++){
		input();
		solve();
	}
	return 0;
}


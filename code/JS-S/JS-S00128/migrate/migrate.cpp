#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
const int N=2e6+5,M=5005;
int c,T;
int n;
ll d;
ll x[N];
int L[N],R[N];
#define pi pair<int,int>
#define fi first
#define se second
pi operator + (const pi &x,const pi &y){
	return {min(x.fi,y.fi),(x.fi<=y.fi?x.se:0)+(y.fi<=x.fi?y.se:0)};
}
pi merge(const pi &x,const pi &y){
	return {x.fi+y.fi,x.se*y.se};
}
struct BIT{
	pi t[M];
	void clear(){
		rep(i,1,n) t[i]={1e9,0};
	}
	void add(int p,const pi &x){
		for(;p;p&=p-1) t[p]=t[p]+x;
	};
	pi query(int p){
		pi res={1e9,0};
		for(;p<=n;p+=p&-p) res=res+t[p];
		return res;
	}
}t[M];
pi f[M][M];
void solve1(){
	rep(u,1,n) rep(v,u,n) f[u][v]={1e9,0};
	rep(u,1,n) t[u].clear();
	rep(u,1,n){
		rep(v,1,L[u]-1) f[v][u]=merge(t[v].query(L[u]),{1,1});
		rep(v,L[u],u-1) f[v][u]={1,1};
		f[u][u]={0,1};
		rep(v,1,u) t[v].add(u,f[v][u]);
	}
	int ans=0;
	rep(i,1,n) rep(j,i+1,n) if(f[i][j].se==2) ++ans;
	cout<<ans<<'\n';
}
void solve2(){
	if(n==1){cout<<"0\n";return;}
	int s=R[1]-1;
	if(s<2){cout<<"0\n";return;}
	if(2*s>n){cout<<"0\n";return;}
	cout<<n-2*s+1<<'\n';
}
void solve3(){
	int mid=-1;
	rep(i,1,n) if(L[i]==1&&R[i]==n) mid=i;
	ll ans=0;
	if(mid!=1&&mid!=n){
		if(R[mid-1]==mid+1) ans+=n-mid-1;
		int cnt=0;
		rep(i,1,n) if(R[i]==mid) ++cnt;
		ans+=1LL*(R[mid-1]-R[mid-2])*cnt;
		cnt=0;
		if(L[mid+1]==mid-1) ans+=mid-2;
		rep(i,1,n) if(L[i]==mid) ++cnt;
		ans+=1LL*(L[mid+2]-L[mid+1])*cnt;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		rep(i,1,n) cin>>x[i];
		for(int i=1,j=1;i<=n;++i){
			while(x[i]-x[j]>d) ++j;
			L[i]=j;
		}
		for(int i=n,j=n;i>0;--i){
			while(x[j]-x[i]>d) --j;
			R[i]=j;
		}
		if(c<=10) solve1();
		else if(c<=12) solve2();
		else if(c<=14) solve3();
	}
	return 0;
}

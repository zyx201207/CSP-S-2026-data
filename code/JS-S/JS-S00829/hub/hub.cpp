#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) rept(i,0,n)
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define il inline
#define re return
#define pb push_back
#define db double
#define ld long db
#define int long long
using namespace std;
template<typename T>void Mx(T&x,T y){if(x<y)x=y;}
template<typename T>void Mi(T&x,T y){if(x>y)x=y;}
const int MOD=998244353,INF=1000000000000000000;
void FIO(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int N=1000006;
vi v[N];
int n,m;
int fa[N],dep[N];
void dfs1(int u,int p,int d){
	fa[u]=p;
	dep[u]=d;
	for(int i:v[u])if(i!=p)
		dfs1(i,u,d+1);
}
int rlim,nf[N];
void dfs2(int u,int p){
	nf[u]=0;
	fa[u]=p;
	for(int i:v[u])if(i!=p){
		dfs2(i,u);
		Mx(nf[u],nf[i]+1);
	}
}
void pre(){
	dfs1(0,0,0);
	int mp=0;
	rep(i,n)if(dep[i]>dep[mp])mp=i;
	dfs1(mp,mp,0);
	rep(i,n)if(dep[i]>dep[mp])mp=i;
	rlim=(dep[mp]+1)/2;
	rep(_,rlim)mp=fa[mp];
	dfs2(mp,mp);
}
int el[N],vv[N],vt;
int calc(){
	int la=0;
	rep(i,vt)el[i]=la=min(la+1,vv[i]);
	int ans=0;
	la=0;
	for(int i=vt-1;~i;i--){
		Mx(ans,el[i]+la);
		la=min(la+1,vv[i]);
	}
	Mx(ans,la);
	re ans;
}
bool vis[N];
int smx[N],deg[N],cid[N][2];
bool chk(int cm){
	int cnt=0;
	rep(i,n)cnt+=(nf[i]>=cm);
	cnt-=m;
	if(cnt<=0)re 1;
	if(cnt>cm*2)re 0;
	rep(i,n){
		vis[i]=0;
		smx[i]=-1;
		deg[i]=0;
	}
	rep(i,n)if(nf[i]>=cm){
		for(int j:v[i]){
			if(nf[j]>=cm){
				if(deg[i]<2)cid[i][deg[i]]=j;
				deg[i]++;
			}
			else{
				Mx(smx[i],nf[j]);
			}
		}
	}
	rep(i,n)if(nf[i]<=cm||deg[i]!=2){
		vis[i]=1;
	}
	rep(i,n)if(!vis[i]){
		vt=1;vv[0]=i;
		vis[i]=1;
		int cur=cid[i][0],las=i;
		while(!vis[cur]){
			vis[cur]=1;
			vv[vt++]=cur;
			int nx=cid[cur][cid[cur][0]==las];
			las=cur;cur=nx;
		}
		reverse(vv,vv+vt);
		cur=cid[i][1],las=i;
		while(!vis[cur]){
			vis[cur]=1;
			vv[vt++]=cur;
			int nx=cid[cur][cid[cur][0]==las];
			las=cur;cur=nx;
		}
		if(vt<cnt)continue;
		rep(j,vt)vv[j]=cm-1-smx[vv[j]];
		if(calc()>=cnt)re 1;
	}
	re 0;
}
void run(){
	cin>>n>>m;
	rep(i,n)v[i].clear();
	rep(i,n-1){
		int x,y;cin>>x>>y;
		v[--x].pb(--y);
		v[y].pb(x);
	}
	pre();
	if(m==1){
		cout<<rlim<<"\n";
		re;
	}
	if(m==n){
		cout<<0<<"\n";
		re;
	}
	int l=1,r=rlim;
	while(l<r){
		int cm=(l+r)>>1;
		if(chk(cm))r=cm;
		else l=cm+1;
	}
	cout<<l<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FIO("hub");
	int T=1;
	int _C;
	cin>>_C>>T;
	while(T--)
		run();
	re 0;
}
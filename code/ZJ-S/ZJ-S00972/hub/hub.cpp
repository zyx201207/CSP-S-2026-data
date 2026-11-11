#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
ld eps=1e-12,d=0.997;
int ans,bst,nw;
mt19937 rnd(time(0));
inline ld Rand(){return (ld)rnd()/rnd.max();}
#define N 100005
int _,n,k,vis[N];
vector<int>a[N];
vector<int>f,s;
#define gc getchar
inline int read(){
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+(c^48);
	return k*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);putchar('0'+x%10);
}
inline void dfs(int u,int fa){
	if((int)f.size()<k)f.push_back(u),vis[u]=1;
	else s.push_back(u);
	for(int v:a[u])if(v!=fa)dfs(v,u);
}
inline void Dfs(int u,int fa,int dep,int &p){
	if(vis[u])p=min(dep,p);
	for(int v:a[u])if(v!=fa)Dfs(v,u,dep+1,p);
}
inline int check(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;int p=n;
		Dfs(i,0,0,p);res=max(res,p);
	}
	return res;
}
inline void Solve(){
	ld T=300;ans=check();bst=min(ans,bst);
	while(T>eps){
		int xx=rnd()%k,yy=rnd()%(n-k),x=f[xx],y=s[yy],r1=1,r2=1;
		for(int p:a[x])if(vis[p] || p==y)r1=0;vis[x]=0;
		for(int p:a[y])if(vis[p])r2=0;vis[y]=1;
		if(nw-r1+r2>2){T*=d;vis[x]=1;vis[y]=0;continue;}
		swap(f[xx],s[yy]);int res=check(),tmp=ans-res;
//		if(res==1){for(int i=1;i<=n;i++)write(vis[i]),putchar(' ');putchar('\n');}
		if(tmp>0 || exp(tmp/T)>Rand())ans=res,nw=nw-r1+r2;
		else swap(f[xx],s[yy]),vis[x]=1,vis[y]=0;//write(ans);putchar('\n');
		bst=min(ans,bst);T*=d;
	}
}
inline void solve(){
	n=read();k=read();f.clear();s.clear();bst=n;
	for(int i=1;i<=n;i++)a[i].clear(),vis[i]=0;
	for(int i=1;i<n;i++){
		int l,r;cin>>l>>r;
		a[l].push_back(r);
		a[r].push_back(l);
	}
	dfs(1,0);nw=1;
//	for(int x:f)write(x),putchar(' ');putchar('\n');
	if(k==n){write(0);putchar('\n');return;}
//	write(check());putchar('\n');
	for(int i=1;i<=5;i++)Solve();
	write(bst);putchar('\n');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;_=read();T=read();while(T--)solve();
	return 0;
}
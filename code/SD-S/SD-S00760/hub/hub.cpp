#include<bits/stdc++.h>
//#define int long long
#define fi first
#define se second
#define pii std::pair<int,int>
#define vint std::vector<int>
#define vpair std::vector<pii>
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define debug(...) fprintf(stderr,##__VA_ARGS__)

template<typename T>
void read(T&x){
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	x*=f;
}
std::stack<char>st;
template<typename T>
void print(T x){
	if(x==0)putchar('0');
	if(x<0)putchar('-'),x=-x;
	while(x)st.push('0'+x%10),x/=10;
	while(SZ(st))putchar(st.top()),st.pop();
}
template<typename T>
void printsp(T x){print(x),putchar(' ');}
template<typename T>
void println(T x){print(x),putchar('\n');}
template<typename T,typename I>
bool chkmin(T&a,I b){
	if(a>b)return a=b,1;
	return 0;
}
template<typename T,typename I>
bool chkmax(T&a,I b){
	if(a<b)return a=b,1;
	return 0;
}

bool Mbe;

const int maxn=1e6+10,inf=1e9;

int cid,T,n,k,u[maxn],v[maxn],sz[maxn],b[maxn],h[maxn],id,mi,M,f[maxn],dep[maxn],mx[maxn],bel[maxn];
std::vector<pii>a[maxn];
vint son[maxn];
std::vector<std::array<int,3> >V[2];
vpair l1[maxn],l0[maxn];

void dfs0(int p,int fa,int q){
	sz[p]=1;
	for(pii i:a[p])if(i.fi!=fa)dfs0(i.fi,p,i.se),sz[p]+=sz[i.fi];
	if(chkmin(mi,std::max(sz[p],n-sz[p])))id=q;
}
void dfs1(int p,int fa,int d,int o){
	bel[p]=o;
	h[p]=0;
	dep[p]=d;
	for(pii i:a[p])if(i.fi!=fa){
		son[p].eb(i.fi);
		dfs1(i.fi,p,d+1,o);
		chkmax(h[p],h[i.fi]+1);
	}
}
void dfs2(int p,int fa,vint&o){
	b[p]=-inf;
	for(int i=SZ(o)-1,j=1;~i;i--,j++){
//		debug("p=%d o=%d\n",p,o[i]);
		if(o[i]+j<=M)continue;
		chkmax(b[p],o[i]+dep[p]-j);
	}
	int H=0,ch=-inf,c=p;
	for(int i:son[p])
		if(h[i]+1>H)ch=H,H=h[i]+1,c=i;
		else if(h[i]+1>ch)ch=h[i]+1;
	for(int i:son[p])if(i!=fa){
		if(i==c){
			o.eb(ch);
			dfs2(i,p,o);
			o.pop_back();
		}
		else{
			o.eb(H);
			dfs2(i,p,o);
			o.pop_back();
		}
	}
}
void dfs3(int p,int fa,int q){
	f[p]=1;
	for(int i:son[p])dfs3(i,p,q);
	for(int i:son[p])if(h[i]+1>M)f[p]+=f[i];
	V[q].push_back({f[p],M-b[p]-1,dep[p]});//f'<=k-f[p] dep<=M-b[p]-1
//	debug("M=%d p=%d f=%d b=%d %d\n",M,p,f[p],b[p],h[p]);
}
bool solve(){
	V[0].clear(),V[1].clear();
	vint o;
	dfs2(u[id],v[id],o);
	dfs3(u[id],v[id],0);
	o.clear();
	dfs2(v[id],u[id],o);
	dfs3(v[id],u[id],1);
	std::sort(all(V[0]));
	std::sort(all(V[1]));
	for(int i=0;i<=n;i++)l1[i].clear(),l0[i].clear();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(bel[i]!=bel[j]&&f[i]+f[j]<=k&&M-b[i]-1>=dep[j]&&M-b[j]-1>=dep[i])return 1;
	return 0;
	for(std::array<int,3> i:V[0]){
		int l=0,r=SZ(V[1])-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(V[1][mid][0]+i[0]<=k)l=mid+1;
			else r=mid-1;
		}
//		debug("(%d %d %d) %d\n",i[0],i[1],i[2],l);
		if(!l)continue;
		l1[l-1].eb(i[1],i[2]);
	}
	for(std::array<int,3> i:V[1]){
		int l=0,r=SZ(V[0])-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(V[0][mid][0]+i[0]<=k)l=mid+1;
			else r=mid-1;
		}
		if(!l)continue;
		l0[l-1].eb(i[1],i[2]);
	}
	for(int i=0;i<SZ(V[1]);i++){
		for(pii j:l1[i]){
			int t=j.se,o=j.fi;
			for(int k=0;k<=i;k++){
//				debug("%d %d %d %d\n",t,o,V[1][k][2],V[1][k][1]);
				if(V[1][k][2]<=o&&t<=V[1][k][1])return 1;
			}
		}
	}
	for(int i=0;i<SZ(V[0]);i++){
		for(pii j:l0[i]){
			int t=j.se,o=j.fi;
			for(int k=0;k<=i;k++)
				if(V[0][k][2]<=o&&t<=V[0][k][1])return 1;
		}
	}
	return 0;
}

bool Men;

signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(cid),read(T);
	while(T--){
		read(n),read(k);mi=inf;
		for(int i=1;i<=n;i++)a[i].clear(),son[i].clear();
		for(int i=1;i<n;i++)read(u[i]),read(v[i]),a[u[i]].eb(v[i],i),a[v[i]].eb(u[i],i);
		if(n==k){
			println(0);
			continue;
		}
		dfs0(1,0,0);
		dfs1(u[id],v[id],0,0),dfs1(v[id],u[id],0,1);
//		debug("(%d,%d)\n",u[id],v[id]);
		if(k==1){
			println((h[u[id]]+h[v[id]]+1+1)/2);
			continue;
		}
		int l=1,r=(h[u[id]]+h[v[id]]+1)/2;
		while(l<=r){
			M=(l+r)>>1;
			if(solve())r=M-1;
			else l=M+1;
		}
		println(r+1);
	}
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

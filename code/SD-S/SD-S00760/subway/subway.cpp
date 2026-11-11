#include<bits/stdc++.h>
#define int long long
#define pii std::pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define vint std::vector<int>
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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

const int maxn=5e5+10,inf=1e18;

int cid,n,m,d,q,w[maxn],dis[510][510];
std::vector<pii>v[maxn];

bool Men;

signed main(){
//	system("fc subway.out subway7.ans");return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(cid),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,x,t;j<=k;j++)read(x),read(t),v[x].eb(i,t);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<SZ(v[i]);j++)
			for(int k=j+1;k<SZ(v[i]);k++)chkmin(dis[v[i][j].fi][v[i][k].fi],v[i][j].se+v[i][k].se);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)chkmin(dis[i][j],dis[j][i]),chkmin(dis[j][i],dis[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)chkmin(dis[j][k],dis[i][j]+dis[i][k]);
	for(int i=1,l,r;i<=q;i++){
		read(l),read(r);
		int ans=inf;
		for(int j=0;j<SZ(v[l]);j++)for(int k=0;k<SZ(v[r]);k++)chkmin(ans,v[l][j].se+v[r][k].se+dis[v[l][j].fi][v[r][k].fi]);
		println(ans+w[l]+w[r]);
	}
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

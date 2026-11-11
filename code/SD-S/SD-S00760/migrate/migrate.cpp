#include<bits/stdc++.h>
#define int long long
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

const int maxn=2e6+10;

int cid,T,n,d,x[maxn],f[maxn],g[maxn],ans,t[maxn],w[maxn],p0[maxn],p1[maxn],p2[maxn],w0[maxn];

bool Men;

signed main(){
//	system("fc migrate.out migrate6.ans");return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(cid),read(T);
	while(T--){
		read(n),read(d);ans=0;
		for(int i=1;i<=n;i++)read(x[i]);
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];chkmax(f[i],i);
			while(f[i]<n&&x[f[i]+1]-x[i]<=d)f[i]++;
		}
		g[n+1]=n+1;
		for(int i=n;i;i--){
			g[i]=g[i+1];chkmin(g[i],i);
			while(g[i]>1&&x[i]-x[g[i]-1]<=d)g[i]--;
		}
		int L=0,R=0;
		for(int i=0;i<=n;i++)t[i]=w[i]=w0[i]=p0[i]=p1[i]=p2[i]=0;
		t[0]=1;
		for(int i=1;i<=n;i++)if(i!=f[i]){
			while(R<f[i]){
				R++;
				t[g[R]]++;
			}
			while(L<i+1){
				t[g[L]]--;
				L++;
			}
			w[i]=t[i-1];
			w0[i]=t[i];
//			if(n<=10)debug("i=%lld L=%lld R=%lld %lld\n",i,L,R,t[i-1]);
		}
		for(int i=n;i;i--)if(i!=f[i]){
			int anc=f[f[i]];
			if(anc==f[i])continue;
			p2[i]=w[f[i]];
			p0[i]=w0[f[i]];
//			if(n<=10)debug("i=%lld anc=%lld w0=%lld %lld\n",i,anc,w0[f[i]],p0[i]);
			if(g[anc]==f[i])p0[i]+=p0[f[i]],p1[i]+=p1[f[i]];
			if(anc-1>f[i]&&g[anc-1]==f[i])p1[i]+=p2[f[i]];
			if(f[i]-1>i&&g[anc]==f[i]-1)p2[i]+=p0[f[i]];
//			p[i]=p[f[i]];
//			if(f[i]!=i+1)p[i]+=w[f[i]];
			ans+=p1[i]+p2[i];
		}
//		if(n<=10)for(int i=1;i<=n;i++)debug("i=%lld f=%lld g=%lld w=%lld w0=%lld p0=%lld p1=%lld p2=%lld\n",i,f[i],g[i],w[i],w0[i],p0[i],p1[i],p2[i]);
		println(ans);
	}
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

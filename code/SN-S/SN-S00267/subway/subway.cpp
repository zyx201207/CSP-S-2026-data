#include <bits/stdc++.h>
using namespace std;
#define il inline
#define lld int64_t
#define pii array<int,2>
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char ibuf[LEN],obuf[LEN],tbuf[20],*p1=ibuf,*p2=ibuf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(int &x){
		char ch=gc();x=0;
		while(ch< '0'||ch> '9')ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
	il void read(int &x,auto &...y){read(x),read(y...);}
	il void write(lld x){
		short top=0;
		do tbuf[top++]=x%10;while(x/=10);
		while(top)pc(tbuf[--top]|48);
		pc('\n');
	}
}
using namespace FastIO;

const int N=505,M=5e5+5;
const lld INF=1e18;

int o,n,m,k,d,q,a,t,u,v,w[M];
lld dis[N][N];
vector<pii>pat[M];
il void main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	read(o,n,m,d,q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(k);
		for(int j=1;j<=k;j++){
			read(a,t);
			pat[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		k=pat[i].size();
		for(int x=0;x<k;x++){
			int c=pat[i][x][0],wc=pat[i][x][1];
			for(int y=0;y<k;y++){
				int d=pat[i][y][0],wd=pat[i][y][1];
				dis[c][d]=min(dis[c][d],(lld)wc+wd);
				dis[d][c]=min(dis[d][c],(lld)wc+wd);
			}
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				lld tmp=dis[p][i]+dis[p][j];
				dis[i][j]=min(dis[i][j],tmp);
			}
		}
	}
	for(int i=1;i<=q;i++){
		read(u,v);
		int ku=pat[u].size();
		int kv=pat[v].size();
		lld ans=INF;
		for(int x=0;x<ku;x++){
			int c=pat[u][x][0],wc=pat[u][x][1];
			for(int y=0;y<kv;y++){
				int d=pat[v][y][0],wd=pat[v][y][1];
				ans=min(ans,dis[c][d]+wc+wd);
			}
		}
		write(ans+w[u]+w[v]);
	}
}}
int main(){DYC::main(),DYC::flush();}

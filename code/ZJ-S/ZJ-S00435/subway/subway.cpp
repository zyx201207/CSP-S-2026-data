#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
namespace io{
	int read(){
		int x=0,y=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') y=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		return x*y;
	}
	void output(int x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9) output(x/10);
		putchar(x%10|48);
	}
}
#define read() io::read()
#define output(x) io::output(x)
namespace Czming__{
	struct graph{
		int nxd[1000001],to[1000001],first[500001],cnt;
		void add(int u,int v,bool flag){
			to[++cnt]=v;
			nxd[cnt]=first[u];
			first[u]=cnt;
			if(flag==false) add(v,u,false);
		}
	};
	int ai,ti,ki,w[500001],mi[501][501],n,m,q,d,sums[500001][21],cnt[500001],tim[500001][21];
	void init(){return ;}
	void work(){
		n=read();
		m=read();
		d=read();
		q=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) mi[i][j]=1e12;
			mi[i][i]=0;
		}
		for(int i=1;i<=m;i++) w[i]=read();
		for(int i=1;i<=n;i++){
			ki=read();
			while(ki--){
				ai=read();
				ti=read();
				sums[ai][++cnt[ai]]=i;
				tim[ai][cnt[ai]]=ti;	
			}	
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=cnt[i];j++){
				for(int k=1;k<=cnt[i];k++) mi[sums[i][j]][sums[i][k]]=min(mi[sums[i][j]][sums[i][k]],tim[i][j]+tim[i][k]);
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) mi[i][j]=min(mi[i][j],mi[i][k]+mi[k][j]);
			}
		}
		int xi,yi,answer;
		while(q--){
			xi=read();
			yi=read();
			answer=1e18;
			for(int i=1;i<=cnt[xi];i++){
				for(int j=1;j<=cnt[yi];j++) answer=min(answer,mi[sums[xi][i]][sums[yi][j]]+tim[xi][i]+tim[yi][j]);
			}
			output(answer+w[xi]+w[yi]);
			puts("");
		}
		return ;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id=read(),T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
fc subway1.out subway1.ans
fc subway2.out subway2.ans
fc subway3.out subway3.ans
fc subway4.out subway4.ans
fc subway5.out subway5.ans
fc subway6.out subway6.ans
fc subway7.out subway7.ans
*/

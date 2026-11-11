#include<bits/stdc++.h>
using namespace std;
#define int long long
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
			if(flag) add(v,u,false);
		}
	}g;
	int m,a[500001],n,answer[500001],siz[500001],lst[500001],fa[500001];
	void init(){}
	void work(){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		lst[a[n]]=n;
		for(int i=n-1;i;i--){
			if(lst[a[i]]){
				g.add(fa[lst[a[i]]],i,false);
				fa[i]=fa[lst[a[i]]];
			}
			else{
				g.add(i+1,i,false);
				fa[i]=i+1;
			}
			lst[a[i]]=i;
		}
		for(int x=1;x<=n;x++){
			siz[x]=1;
			for(int i=g.first[x],to;i;i=g.nxd[i]){
				to=g.to[i];
				siz[x]+=siz[to];
			}
			answer[a[x]]+=siz[x];
		}
		for(int i=1;i<=m;i++){
			output(answer[i]);
			if(i!=m) putchar(' ');
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
cd /d E:\ZJ-J00406\card
fc card1.out card1.ans
fc card2.out card2.ans
fc card3.out card3.ans
fc card4.out card4.ans
fc card5.out card5.ans
fc card6.out card6.ans
*/

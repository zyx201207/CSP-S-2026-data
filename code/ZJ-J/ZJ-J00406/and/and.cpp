#include<bits/stdc++.h>
using namespace std;
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
	int siz[6000001],ord,ans,val,ne,cntz,nxd[6000001][2],answer[2][200001],cnt[2],n,ai,sums,m;
	void init(){}
	void work(){
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			ai=read();
			ne=0;
			siz[ne]++;
			for(int j=30;j>=0;j--){
				val=((ai>>j)&1);
				if(nxd[ne][val]==0){
					nxd[ne][val]=(++cntz);
				}
				ne=nxd[ne][val];
				siz[ne]++;
			}
		}
		cnt[0]=cnt[1]=0;
		answer[1][++cnt[1]]=0;
		for(int j=30;j>=0;j--){
			sums=0;
			ord=(j&1);
			//1
			for(int i=1;i<=cnt[ord^1];i++){
				if(nxd[answer[ord^1][i]][1]) sums+=siz[nxd[answer[ord^1][i]][1]];
			}
			cnt[ord]=0;
			if(sums>=m) ans|=(1<<j);
			else{
				for(int i=1;i<=cnt[ord^1];i++){
					if(nxd[answer[ord^1][i]][0]) answer[ord][++cnt[ord]]=nxd[answer[ord^1][i]][0];
				}				
			}
			for(int i=1;i<=cnt[ord^1];i++){
				if(nxd[answer[ord^1][i]][1]) answer[ord][++cnt[ord]]=nxd[answer[ord^1][i]][1];
			}
		}
		output(ans);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
cd /d E:\ZJ-J00406\and
fc and1.out and1.ans
fc and2.out and2.ans
fc and3.out and3.ans
fc and4.out and4.ans
fc and5.out and5.ans
fc and6.out and6.ans
*/

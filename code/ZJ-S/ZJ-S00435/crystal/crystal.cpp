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
	int n,m,p,a[500001],answer,sums;
	void init(){return ;}
	void work(){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(p<i){
				p=i;
				sums=0;
			}
			while(p<n&&sums+(a[p+1]-a[p])*(p-i+1)<=m){
				sums+=(a[p+1]-a[p])*(p-i+1);
				p++;
			}
			answer=max(answer,p-i+1);
			//del i
			sums-=a[p]-a[i];
		}
		output(answer);
		return ;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
fc crystal1.out crystal1.ans
fc crystal2.out crystal2.ans
fc crystal3.out crystal3.ans
fc crystal4.out crystal4.ans
*/

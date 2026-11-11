#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IO{
	inline ll read(){
		ll res=0;
		bool flg=true;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-') flg=false;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			res=(res<<3)+(res<<1)+(c&15);
			c=getchar();
		}return flg?res:-res;
	}
	inline void print(ll num){
		if(num>9) print(num/10);
		putchar('0'+num%10);
		return;
	}
	inline void write(ll num){
		if(num<0) putchar('-'),num=-num;
		print(num);
		putchar('\n');
		return;
	}
}
using namespace IO;
const int kMaxN=2e6+5;
int n,T,id;
ll m,a[kMaxN];
inline void Solve(){
	
	return;
}
inline void SolveA(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	if(n%4==3){
		m=n/4;
		write((m+1)/2);
	}
	else{
		m=n/4;
		write(m/2+1);
	}
	return;
}
int main(){
	freopen("hub5.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i;
	id=read(),T=read();
//	if(id==13||id==14){
		SolveA();
		return 0;
//	}
	for(;T;--T){
		n=read(),m=read();
		for(i=1;i<=n;++i) a[i]=read();
		Solve();
	}
	return 0;
}
/*





*/

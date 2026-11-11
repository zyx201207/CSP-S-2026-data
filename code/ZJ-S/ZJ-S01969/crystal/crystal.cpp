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
const int kMaxN=5e5+5;
int n,ans=1;
ll m,a[kMaxN],qa[kMaxN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	n=read(),m=read();
	for(i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i) qa[i]=qa[i-1]+a[i];
	for(i=1,j=1;j<=n;){
		if((ll)(j-i+1)*a[j]-(qa[j]-qa[i-1])<=m){
			ans=max(ans,j-i+1);
			++j;
		}
		else ++i;
	}
	write(ans);
	return 0;
}
/*





*/

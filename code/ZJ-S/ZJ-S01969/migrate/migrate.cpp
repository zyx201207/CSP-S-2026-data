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
const int kMaxN=2e6+5,kMaxM=5e3+5;
int n,id,T;
ll m,a[kMaxN],ans;
int mn[kMaxM],mx[kMaxM];
ll f[kMaxM][kMaxM];
inline void solve(int st){
	int i,j,k;
	for(i=st;i<=n;++i) mn[i]=0,mx[i]=n;
	for(i=st;i<=n;++i) for(j=0;j<=i-st;++j) f[i][j]=0;
	mn[st]=0,mx[st]=0;
	f[st][0]=1;
	for(i=st+1;i<=n;++i){
		for(j=i-1;j>=st&&a[i]-a[j]<=m;--j){
			for(k=mn[j];k<=mx[j];++k){
				f[i][k+1]+=f[j][k];
			}
		}
		for(j=0;j<=n;++j){
			if(f[i][j]){
				mn[i]=j;
				break;
			}
		}
		for(j=n;j>=0;--j){
			if(f[i][j]){
				mx[i]=j;
				break;
			}
		}
		if(f[i][mn[i]]==2) ++ans;
	}return;
}
inline void Solve(){
	ans=0;
	int i;
	for(i=1;i<=n;++i)
		solve(i);
	write(ans);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int i;
	id=read(),T=read();
	for(;T;--T){
		ans=0;
		n=read(),m=read();
		for(i=1;i<=n;++i) a[i]=read();
		Solve();
	}
	return 0;
}
/*





*/

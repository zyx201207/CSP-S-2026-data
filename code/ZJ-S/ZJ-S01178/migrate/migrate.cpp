#include<bits/stdc++.h>
#define ll long long
#define gc getchar
#define endl puts("");
#define int ll
using namespace std;
namespace linan05006_hxy{
	inline int read(){int s=0,w=1;char c=gc();while(c>'9'||c<'0'){if(c=='-')w=-1;c=gc();}while(c<='9'&&c>='0')s=(s<<3)+(s<<1)+c-'0',c=gc();return s*w;}
	inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
}
using namespace linan05006_hxy;
int const N=2e6+5;
int c,x[N];
inline void solve(){
	int n=read(),d=read(),cnt=0;
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n-3;i++){
		if(x[i+3]-x[i]>d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d)cnt++;
	}
	write(cnt),endl;
}
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	int _=1;
	c=read(),_=read();
	for(int i=1;i<=_;i++)solve();
	return 0;
}

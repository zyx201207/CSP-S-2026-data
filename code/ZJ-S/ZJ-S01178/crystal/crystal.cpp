#include<bits/stdc++.h>
#define ll long long
#define gc getchar
#define endl puts("");
#define int ll
using namespace std;
namespace linan05006_hxy{
	inline int read(){int s=0,w=1;char c=gc();while(c>'9'||c<'0'){if(c=='-')w=-1;c=gc();}while(c<='9'&&c>='0')s=(s<<3)+(s<<1)+c-'0',c=gc();return s*w;}
	inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
	int score=100;
}
using namespace linan05006_hxy;
int const N=5e5+5;
int a[N],d[N];
inline void solve(){
	int n=read(),m=read(),ans=1,l,r,mid,tmp;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	for(int l=1,r=1;l<=n;l++){
		while((r-l+1)*a[r]-d[r]+d[l-1]<=m&&r<=n)r++;
		ans=max(ans,r-l);
	}
	write(ans);
}
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	int _=1;
//	_=read();
	for(int i=1;i<=_;i++)solve();
	return 0;
}

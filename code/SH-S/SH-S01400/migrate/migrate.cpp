#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll rd(){ll x=0;char c=gc;bool f=0;while(c<48||c>57) c=='-'&&(f=-1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll c,t,n,d,ans,x[2000009],u[2000009],v[2000009],f[2000009],g[2000009],l[2000009],r[2000009];
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		n=rd(),d=rd(),ans=0;
		for(int i=0;i<=n+1;++i) u[i]=v[i]=f[i]=g[i]=l[i]=r[i]=0;
		for(int i=1;i<=n;++i) x[i]=rd();
		for(int i=1,j=1;i<=n;++i){
			while(j<n&&x[j+1]<=x[i]+d) ++j;
			r[i]=j,j>i&&++u[j],j>i+1&&++f[j-1];
		}
		for(int i=n,j=n;i;--i){
			while(j>1&&x[j-1]>=x[i]-d) --j;
			l[i]=j,j<i&&++v[j],j<i-1&&++g[j+1];
		}
		for(int i=1;i<n;++i) if(l[i]<i&&r[l[i]]==i) u[i]+=u[l[i]];
		for(int i=n;i>1;--i) if(r[i]>i&&l[r[i]]==i) v[i]+=v[r[i]];
		for(int i=1;i<n;++i) if(l[i]<i&&r[l[i]]==i+1) f[i]+=u[l[i]];
		for(int i=n;i>1;--i) if(r[i]>i&&l[r[i]]==i-1) g[i]+=v[r[i]];
		for(int i=1;i<n;++i) ans+=f[i]*g[i+1];
		ot(ans),pc('\n');
	}
	return 0;
}

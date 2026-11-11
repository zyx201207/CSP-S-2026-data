#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll rd(){ll x=0;char c=gc;bool f=0;while(c<48||c>57) c=='-'&&(f=-1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll c,n,m,d,q,k,A,T,x,y,ans,w[500009],f[509][509];
vector<ll> a[500009],b[500009];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd(),memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int i=1;i<=m;++i) w[i]=rd();
	for(int i=1;i<=n;++i){
		k=rd();
		while(k--){
			A=rd(),T=rd();
			for(int j=0,_;j<a[A].size();++j) _=a[A][j],f[i][_]=f[_][i]=min(f[i][_],b[A][j]+T);
			a[A].push_back(i),b[A].push_back(T);
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	while(q--){
		x=rd(),y=rd(),ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=0;i<a[x].size();++i) for(int j=0;j<a[y].size();++j) ans=min(ans,f[a[x][i]][a[y][j]]+b[x][i]+b[y][j]);
		ot(ans+w[x]+w[y]),pc('\n');
	}
	return 0;
}

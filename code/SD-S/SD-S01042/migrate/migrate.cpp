#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;

inline ll read(){
	ll f=1,w=0;
	char ch=getchar();
	for(;ch>'9' or ch<'0';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10),x%=10;
	putchar(x+'0');
}
ll c,t,n,d,a[N],f[N],g[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read(),ans=0;
		for(ll i=1;i<=n;i++) a[i]=read(),f[i]=g[i]=0;
		if(c<=10){
			for(ll i=1;i<=n;i++){
				ll l=i,x=1,l2=i;
				f[l-1]=-1,f[l]=0,g[l2]=1,g[l2-1]=0;
				for(ll j=i+1;j<=n;j++){
	//				unsigned ll y=(unsigned)
					if(a[j]-a[l]>d) l=j-1,x++;
	//				if(a[j]-a[l]<0) write(a[j]-a[l]),putchar(' ');
					if(a[j]-a[l]>d){
						f[j]=-1;
						break;
					}f[j]=x;
	//				if(f[j]==1) g[j]=1;
					while(a[j]-a[l2]>d) l2++;
					g[j]=g[l]-g[l2-1];
					if(g[j]==2) ans++;
					g[j]+=g[j-1];
				}
			}
			write(ans),putchar('\n');
		}
		if(c==11 or c==12){
			ll l=1,x=1,l2=1;
			f[0]=-1,f[1]=0,g[l2]=1,g[0]=0;
			for(ll j=2;j<=n;j++){
				if(a[j]-a[l]>d) l=j-1,x++;
				if(a[j]-a[l]>d){
					f[j]=-1;
					break;
				}f[j]=x;
				while(a[j]-a[l2]>d) l2++;
				g[j]=g[l]-g[l2-1];
				if(g[j]==2) ans+=(n-j+1);
				g[j]+=g[j-1];
			}
			write(ans),putchar('\n');
		}
	}
	return 0;
}

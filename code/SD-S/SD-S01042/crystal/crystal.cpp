#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
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
ll n,a[N],m,f[N],ans,sum,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	l=1,r=1;
	for(;r<=n;r++){
		f[r]=f[r-1]+(r-l)*(a[r]-a[r-1]);
		while(f[r]>m){
			f[r]-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}write(ans);
	return 0;
}

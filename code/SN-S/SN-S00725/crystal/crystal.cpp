#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++) 
inline ll read(){
	char c=getchar(); ll t=1,k=0;
	for(;'0'>c||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;'0'<=c&&c<='9';c=getchar()) k=k*10+(c^48);
	return t*k;
}
ll n,m,l,r,ans,a[maxn],c[maxn];
inline bool check(ll num){
	ll res=0;
	for(int i=1;i<=num;i++)
		res+=c[i]*(i-1);
	if(res<=m) return 1;
	for(int i=num+1;i<=n;i++){
		res-=(a[i-1]-a[i-num]);
		res+=c[i]*(num-1);
		if(res<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) c[i]=a[i]-a[i-1];
	l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1; 
	}
	printf("%lld\n",ans);
	return 0;
}

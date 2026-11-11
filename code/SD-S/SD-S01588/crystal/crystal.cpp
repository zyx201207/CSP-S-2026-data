#include<bits/stdc++.h>
#define il inline 
#define ll long long
using namespace std;
#define rep(x,l,r) for(ll x=l;x<=r;++x)
#define per(x,l,r) for(ll x=l;x>=r;--x)
il ll read(){
	ll f=1,k=0; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}return f*k;
}
const int N=5e5+50;
ll n,a[N],m,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int ans=1;
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	int l=1;
	rep(r,1,n){
		while(l<=r&&(a[r]*(r-l)-(sum[r-1]-sum[l-1])>m)) l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	
	return 0;
}


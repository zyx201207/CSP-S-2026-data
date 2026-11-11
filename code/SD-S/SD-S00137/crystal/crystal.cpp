#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 5e5+6;

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1ll)+(x<<3ll)+(ch^48);
	return x*f; 
}

inline void write(ll x){
	if(x<0){
		putchar('-'),write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}

ll n,m,ans=1,a[maxn],d[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    rep(i,2,n) d[i]=a[i]-a[i-1]; 
    //rep(i,2,n) write(d[i]),putchar(' ');
    ll l=1,cur=0,cnt=0;
    rep(r,1,n){
	    cur+=cnt*d[r],++cnt;
	    while(l<r&&cur>m) cur-=(a[r]-a[l]),--cnt,++l; 
    	
    	ans=max(ans,cnt);
	}
	write(ans),putchar('\n');
	return 0;
}


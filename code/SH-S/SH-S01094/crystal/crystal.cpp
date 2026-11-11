#include<bits/stdc++.h>
#define N 500009
using namespace std;
typedef long long ll;

inline ll read(){
	ll x=0;bool sym=0;char ch=getchar();
	while(!isdigit(ch)) sym^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return sym?-x:x;
}

ll n,m,a[N],s[N],ans=1;

inline void input(){
	n=read(),m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	input();
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=n;i>=2;i--){ //->a[i] 
		ll l=1,r=i,mid=(l+r)>>1;
		while(l<r){
			mid=(l+r)>>1;
			if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;

	return 0;
}

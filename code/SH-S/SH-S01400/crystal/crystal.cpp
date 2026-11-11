#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll rd(){ll x=0;char c=gc;bool f=0;while(c<48||c>57) c=='-'&&(f=-1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll n,m,ans,a[500009],s[500009];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;++i) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;++i){
		ll l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	ot(ans);
	return 0;
}

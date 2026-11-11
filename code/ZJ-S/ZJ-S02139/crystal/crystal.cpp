#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*y;
}

void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
const ll N=5e5+10;
ll n,m,a[N],s[N];

bool chk(ll i,ll u){
	return (i-u)*a[i]-s[i-1]+s[u-1]<=m;
}
ll fnd(ll i){
	ll l=1,r=i;
	while(l<r){
		ll mid=(l+r)>>1;
		if(chk(i,mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=readl(),m=readl();
	for(ll i=1;i<=n;i++)
		a[i]=readl();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll ans=-1;
	for(ll i=1;i<=n;i++){
		ll u=i-fnd(i)+1;
		ans=(u>ans?u:ans);
	}
	writel(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

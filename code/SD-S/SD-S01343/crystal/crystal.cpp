#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
namespace zyx_{

ll read(){
	ll x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}
ll n,m,a[N],sum[N],ans;
ll tar,now;
bool check(int x){
	ll s1=(sum[now]-sum[x-1]);
	ll s2=(now-x+1)*tar;
	return (s2-s1)>m;
}
int my_main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		tar=a[i],now=i;
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		ll res=now-r+1;
		ans=max(ans,res);
	}
	print(ans);
	return 0;
}

}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	zyx_::my_main();
	return 0;
} 

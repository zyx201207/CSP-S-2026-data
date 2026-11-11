#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline ll max(ll x,ll y){
	return x>y?x:y;
}
const int N=5e5+5;
ll T=1,n,m,a[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+1+n);
		ll l=1,r=2,len=r-l+1,res=0;
		while(r<=n){
			res+=(len-1)*(a[r]-a[r-1]);
			while(res>m){
				res-=(a[r]-a[l]);
				l++;
			}
			ans=max(ans,r-l+1);
			r++;
			len=r-l+1;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
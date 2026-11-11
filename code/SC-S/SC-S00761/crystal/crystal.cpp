#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
inline ll read(){
	ll w=0,f=1;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		w=(w<<3)+(w<<1)+(ch^48);
		ch=getchar();
	}
	return f*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int n;
ll a[N],m,sum[N];
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			ll t=(i-mid)*a[i]-(sum[i-1]-sum[mid-1]);
			if(t<=m) r=mid-1,res=i-mid+1;
			else l=mid+1;
		}
		ans=max(ans,res);
	}
	write(ans);
	return 0; 
} 
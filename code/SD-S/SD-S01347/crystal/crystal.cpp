#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+6;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
int a[N],sum[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=n;i;i--){
		if(a[i]-a[i-1]>m) continue;
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])>m) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}

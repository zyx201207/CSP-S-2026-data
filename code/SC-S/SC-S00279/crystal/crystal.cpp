#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define F(i,j,k) for(int i=j;i>=k;--i)
inline int read(){
	int x=0,type=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') type*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*type;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn];
inline bool check(int x){
	f(i,x,n) if(sum[i]-sum[i-x]+m>=a[i]*x) return true;
	return false;
}
inline void work(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read(); 
	f(i,1,n) a[i]=read();
	std::stable_sort(a+1,a+1+n);
	f(i,1,n) sum[i]=sum[i-1]+a[i];
	int L=1,R=n,res=1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)) L=mid+1,res=mid;
		else R=mid-1;
	}
	write(res);
}
signed main(){work();return 0;}
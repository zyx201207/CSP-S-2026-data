#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5,M=25;
int n,m,a[N],l,r,mid,ans,q[N],hed,til,sum[N],y;
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while( isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
	return res*f; 
}
bool check(int x){
	hed=0,til=1;
	for(int i=x;i<=n;i++){
		/*while(hed>=til&&q[til]+x<=i) til++;
		while(hed>=til&&a[q[hed]]<=a[i]) hed--;
		q[++hed]=i;
		if(i>=x){
			y=a[q[til]]*x-sum[i]+sum[i-x];
			if(y<=m) return 1;
		}*/
		y=a[i]*x-sum[i]+sum[i-x];
		if(y<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
} 

#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
	return x*f; 
}
int n,m,a[500005],f[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		int l=1,r=i,mid,k=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(f[i]-f[mid-1])<=m) r=mid-1,k=mid;
			else l=mid+1;
		} 
		sum=max(sum,i-k+1);
	}
	printf("%lld",sum);
	return 0;
}

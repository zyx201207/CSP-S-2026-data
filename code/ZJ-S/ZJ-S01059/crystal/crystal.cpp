#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,cnt=0,del[600005],sum[600005];
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++) del[i]=a[i]-a[i-1];
	sort(del+2,del+n+1);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+del[i];
	for(long long i=1;i<=n;i++){
		if(cnt+sum[i]<=m) ans=i,cnt+=sum[i];
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],pre[500009];
long long read(){
	long long ret=0,ty=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ty=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		ret=ret*10+c-'0',c=getchar();
	return ret*ty;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			long long x=a[i]*(i-mid+1),y=pre[i]-pre[mid-1];
			if(x-y<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 

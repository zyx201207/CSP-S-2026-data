#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c;long long x=0,f=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')f=-f;
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long a[500005],sum[500005];
int n;
long long m;
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=a[i]+sum[i-1];
	for(int i=1,j=1;i<=n;++i){
		while(a[i]*(i-j+1)-(sum[i]-sum[j-1])>m)++j;
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}

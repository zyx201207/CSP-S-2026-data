#include<bits/stdc++.h>
using namespace std;
static inline long long read(){
	char c;long long a=0;bool f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	do a=a*10+(c^48);while(isdigit(c=getchar()));
	return f?a:-a;
}
int n;
long long m;
long long a[500010];
long long sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=0,ans=1;
	for(int r=1;r<=n;++r){
		while((r-l)*a[r]-sum[r]+sum[l]>m)++l;
		ans=max(ans,r-l);
	}
	printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long h[500005],n,m,qz[500005],l,ans,x,mqz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	sort(h+1,h+n+1);
	//for(int i=1;i<=n;i++)printf("%d ",h[i]);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+h[i];
	//printf("\n");
	//for(int i=1;i<=n;i++)printf("%lld ",qz[i]);
	for(int i=1;i<=n;i++){
		while((i-1-l)*h[i]-(qz[i-1]-qz[l])>m)l++;
		ans=max(ans,i-l);
		//printf("\n%d %d %d",i,l,ans);
		if(h[i]<0)mqz++;
	}
	//printf("\n");
	//printf("%lld %lld %lld",ans,n,mqz);
	printf("%lld",ans);
}


#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,maxm=300005;
int n,m,a[maxn],sum[maxm],t[maxm];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j=t[a[j]]+1)sum[a[j]]++;
	for(int i=1;i<=m;i++)
		if(i==m)printf("%d",sum[i]);else printf("%d ",sum[i]);
	return 0;
}
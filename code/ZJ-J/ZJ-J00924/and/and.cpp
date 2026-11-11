#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,m,a[maxn],f[maxn][maxn],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	if(n>2000){printf("%d",a[n-m+1]);return 0;}
	for(int i=1;i<=n;i++)f[1][i]=a[i];
	for(int i=2;i<=m;i++)
	for(int j=i;j<=n;j++)
	for(int k=i-1;k<j;k++)
		f[i][j]=max(f[i][j],f[i-1][k]&a[j]);
	for(int i=m;i<=n;i++)ans=max(ans,f[m][i]);
	printf("%d",ans);
	return 0;
}
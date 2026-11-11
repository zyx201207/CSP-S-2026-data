#include<bits/stdc++.h>
#define LL long long
#define maxn 100005
using namespace std;
int n,m,ans;
int a[maxn];
int f[5005][5005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) f[i][1]=max(f[i-1][1],a[i]);
	
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++){
		f[i][j]=f[i-1][j];
		f[i][j]=max(f[i][j],(f[i-1][j-1]&a[i]));
	}
	printf("%d\n",f[n][m]);
	return 0;
}
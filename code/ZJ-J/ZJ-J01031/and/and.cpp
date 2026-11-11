#include<bits/stdc++.h>
using namespace std;
int read(){int ret=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}return ret;}
long long readl(){long long ret=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}return ret;}
int n,m;
long long f[2005][2005],a[200005],ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=readl();
	sort(a+1,a+1+n);
	f[1][1]=a[1];
	if(n<=2000){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,i);j++){
		    f[i][j]=max(f[i][j],f[i-1][j]);
    		if(j==1) f[i][1]=max(f[i][1],a[i]);
			else f[i][j]=max(f[i][j],a[i]&f[i-1][j-1]);
    	}
	}printf("%lld",f[n][m]);return 0;
	}else{
		ans=a[n-m+1];
		for(int i=n-m+1;i<=n;i++) ans&=a[i];
		printf("%lld",ans);return 0;
	}
}

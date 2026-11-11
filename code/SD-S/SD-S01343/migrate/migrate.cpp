#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5050;
const int inf=1e9;
namespace zyx_{

ll read(){
	ll x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}
ll c,T,n,d;
ll a[N],g[N][N],f[N][N];
int my_main(){
	c=read(); T=read();
	while(T--){
		n=read(),d=read();
		ll cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=f[i][j]=inf;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(a[i]-a[j]<=d){
					g[i][j]=g[j][i]=1;
					f[i][j]=f[j][i]=1;
				}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(g[i][j]>g[i][k]+g[k][j]){
						g[i][j]=g[i][k]+g[k][j];
						f[i][j]=f[i][k]*f[k][j]; 
					}else if(g[i][j]==g[i][k]+g[k][j]){
						f[i][j]+=(f[i][k]*f[k][j]);
					}
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(f[j][i]==2) cnt++;
		print(cnt);
		putchar('\n');
	}
	return 0;
}

}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	zyx_::my_main();
	return 0;
}

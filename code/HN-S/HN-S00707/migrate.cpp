#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int c,t,n,d,a[N];
int vx[N],vy[N];
int fx[N][N],fy[N][N];
int read(){
	int x=0,f=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++)
		a[i]=read();
		int p=1;
		for(int i=1;i<=n;i++){
			while(p<n&&a[p+1]<=a[i]+d)p++;
			vx[i]=p;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(p>1&&a[p-1]>=a[i]-d)p--;
			vy[i]=p;
		}
		for(int i=1;i<=n;i++){
			p=i;fx[i][i]=i;
			while(p<=n){
				for(int j=p+1;j<=vx[p];j++)
				fx[i][j]=fx[i][p]+j;
				if(vx[p]==p)break;
				p=vx[p];
			}
		}
		for(int i=1;i<=n;i++){
			p=i;fy[i][i]=i;
			while(p>0){
				for(int j=p-1;j>=vy[p];j--)
				fy[i][j]=fy[i][p]+j;
				if(vy[p]==p)break;
				p=vy[p];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		if(fx[i][j]==fy[j][i]+1)
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		fx[i][j]=fy[i][j]=0;
		printf("%lld\n",ans);
	}
	return 0;
}

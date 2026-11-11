#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while ('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int pq,t;
int n,g,a[N+5];
int b[N+5][N+5],c[N+5],d[N+5];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	pq=read(),t=read();
	while (t--){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		n=read(),g=read();
		for (int i=1;i<=n;i++){
			a[i]=read();
		}
		for (int i=1;i<=n-3;i++){
			if (a[i+3]-a[i+1]<=g && a[i+3]-a[i]>g){
				b[i][i+3]=1;
			}
		}
		for (int len=4;len<=n;len++){
			for (int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if (a[i+1]-a[i]<=g && a[i+2]-a[i]>g){
					b[i][j]|=b[i+1][j];
				}
				if (a[j]-a[j-1]<=g && a[j]-a[j-2]>g){
					b[i][j]|=b[i][j-1];
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (b[i][j]==1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

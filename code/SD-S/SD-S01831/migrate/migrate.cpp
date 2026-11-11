#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=5e3+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int c,T,n,d,a[N],f[M][M],g[M][M],t[M],sum[M],lst[M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	if(c==11||c==12){
		while(T--){
			n=read(),d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			int lth=d/(a[2]-a[1]);
			int ans=0;
//			printf("LTH%lld\n",lth);
			if(n<2*lth-1||lth<=1){
				puts("0");
				continue;
			}
//			for(int i=lth+1;i<=;i++){
//				if(i>n)break;
				ans=(ans+n-(2*lth-1));
//			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)g[i][i]=1,t[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					t[i]=j;
					break;
				}
			}
		}
//		puts("T:");
//		for(int j=1;j<=n;j++)printf("%lldJ%lld ",j,t[j]);
//		puts("");
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[i][t[j]]+1;
			}
			int l=n;
			for(int j=n;j>=i+1;j--){
				lst[j]=0;
				while(f[i][l]==f[i][j])l--;
				if(f[i][l]==f[i][j]-1)lst[j]=l;
			}
//			puts("LST:");
//			for(int j=i+1;j<=n;j++)printf("%lldJ%lld ",j,lst[j]);
//			puts("");
			sum[i]=g[i][i];
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>d)break;
				g[i][j]=g[i][j]+sum[lst[j]]-sum[t[j]-1];
				sum[j]=sum[j-1]+g[i][j];
//				k=t[j]~(j-1)if(f[i][k]==f[i][t[j]])
			}
//			puts("SUM:");
//			for(int j=i;j<=n;j++)printf("%lldJ%lld ",j,sum[j]);
//			puts("");
			for(int j=i;j<=n;j++)sum[j]=0;
//			puts("F:");
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					printf("%lld ",f[i][j]);
//				}
//				puts("");
//			}
//			puts("G:");
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					printf("%lld ",g[i][j]);
//				}
//				puts("");
//			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(g[i][j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=g[i][j]=0;
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

*/
/*
作为退役一年后的第一战
打的应该还算可以
希望成绩能如我所愿吧 
*/

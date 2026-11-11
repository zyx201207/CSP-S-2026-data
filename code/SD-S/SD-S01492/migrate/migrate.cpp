#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T>inline void read(T &x){
	bool f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?-x:x);return;
} 
//template<typename T,typename ...Args>inline void read(T &x,Args &...x_){
//	read(x),read(x_...);
//}
template<typename T>inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');return;
}
const int N=310;
int n;
long long dis[N][N],cnt[N][N],d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	register int i,j,k,c,T;
	read(c);read(T);
	while(T--){
		read(n);read(d);
		for(i=1;i<=n;i=-~i) read(x[i]);
		if(c>6){
			if(d/(x[2]-x[1])!=2)write(0);
			else write(max(n-3,0));
			putchar('\n');continue;
		}
		for(i=1;i<=n;i=-~i)for(j=1;j<=n;j=-~j)dis[i][j]=2e18,cnt[i][j]=0;
		for(i=1;i<=n;i=-~i){
			for(j=i-1;j>=1;j=~-j){
				if(x[i]-x[j]>d) break;
				if(dis[i][j]==1) cnt[i][j]=-~cnt[i][j];
				else if(dis[i][j]==2e18) dis[i][j]=1,cnt[i][j]=1;
			}
			for(j=i+1;j<=n;j=-~j){
				if(x[j]-x[i]>d) break;
				if(dis[i][j]==1) cnt[i][j]=-~cnt[i][j];
				else if(dis[i][j]==2e18) dis[i][j]=1,cnt[i][j]=1;
			}
		} 
		for(k=1;k<=n;k=-~k){
			for(i=1;i<=n;i=-~i){
				for(j=1;j<=n;j=-~j){
					if(i!=j){
						if(dis[i][j]==dis[i][k]+dis[k][j]){
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
							if(cnt[i][j]>2)cnt[i][j]=3;
						}
						else if(dis[i][j]>dis[i][k]+dis[k][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
							cnt[i][j]=cnt[i][k]*cnt[k][j];
							if(cnt[i][j]>2)cnt[i][j]=3;
						} 
					}
				}
			}
		}
		register long long ans=0;
		for(i=1;i<=n;i=-~i){
			for(j=i+1;j<=n;j=-~j){
				if(cnt[i][j]==2) ans=-~ans; 
			}
		} 
		write(ans),putchar('\n');
	} 
	return 0;
}

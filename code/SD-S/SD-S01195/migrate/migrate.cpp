#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e6+5;
const long long inf=4.1e18;
int read() {
	int x=0;
	char ch=getchar();
	while(ch<48) ch=getchar();
	while(ch>=48) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
long long readll() {
	long long x=0,fl=1;
	char ch=getchar();
	while(ch<48&&ch!=45) ch=getchar();
	if(ch==45) {
		fl=-1;
		ch=getchar();
	}
	while(ch>=48) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*fl;
}
int tc,t,n,l[N],r[N],nxts[N][23],c[N][23],nxta[N][23],nxtp[N];
long long d,a[N],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	tc=read();t=read();
	while(t--) {
		n=read();d=readll();
		for(int i=1;i<=n;i++) a[i]=readll();
		if(tc==11||tc==12) {
			if(n==1) {
				printf("0\n");
				continue;
			}
			long long c=d/(a[2]-a[1]);
			if(c<=1) printf("0\n");
			else printf("%lld\n",max(n-(c<<1)+1,0ll));
			continue;
		}
		int p=1;
		a[n+1]=inf;
		a[0]=-inf;
		for(int i=1;i<=n;i++) {
			while(a[p]-a[i]<=d) ++p;
			nxts[i][0]=p-1;
		}
		for(int i=n;i;i--) {
			while(a[i]-a[p]<=d) --p;
			nxtp[i]=p+1;
			l[p+1]=i;
			r[p+1]=max(r[p+1],i);
		}
		for(int i=1;i<=21;i++) {
			for(int j=1;j<=n;j++) nxts[j][i]=nxts[nxts[j][i-1]][i-1];
		}
		for(int i=1;i<=n;i++) {
//			printf("%d %lld!!!\n",i,ans);
			int p=i,fl=1;
			while(nxts[p][0]!=p) {
//				printf("%d %d %d???\n",p,nxts[p][0],nxts[p][1]);
				for(int j=nxts[p][0]+1;j<=nxts[p][1];j++) {
//					printf("%d %d %d\n",p,j,nxtp[j]);
					if(nxtp[j]==nxts[p][0]-1&&max(nxtp[nxts[p][0]-1],i)==p) {
						++ans;
//						printf("> %d %d\n",i,j);
					}
				}
				if(max(nxtp[nxts[p][0]],i)<p) {
					fl=p-1-nxtp[nxts[p][0]];
					break;
				}
				p=nxts[p][0];
			}
			if(fl) continue;
//			printf("here\n");
			p=nxts[p][0];
			while(nxts[p][0]!=p) {
				for(int j=p+1;j<=nxts[p][0];j++) {
					if(nxtp[j]==p) {
						++ans;
//						printf("< %d %d\n",i,j);
					}
				}
				if(nxtp[nxts[p][0]]!=p) break;
				p=nxts[p][0];
			}
		}
		printf("%lld\n",ans);
		ans=0;
		for(int i=1;i<=n;i++) l[i]=r[i]=0;
	}
	return 0;
}
/*
游记：https://www.luogu.com.cn/article/vo1uk7d5
blue

18:26
48pts
So bad()If I have 1 more hour,I can get 100pts(我会正解了，但是没有时间了） 
*/

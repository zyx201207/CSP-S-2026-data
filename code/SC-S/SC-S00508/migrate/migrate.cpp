#include<bits/stdc++.h>
using namespace std;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rint register unsigned int
#define rshort register unsigned short
char buf[1<<20],*p1,*p2;
template<typename T> inline void read(T& x){
	x=0;int f=1;char c=gc();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=gc();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
	x*=f;
}
template<typename T> inline void print(T x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10^48);
}
const long long T=1000000000000000000;
unsigned int tx,t,n,nxt[2000005],x,y,ans[2000005],b[2000005],l,r,md,k,k1;
long long ps;
unsigned long long a[2000005],d,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(tx),read(t);
	while(t--){
		read(n),read(d);
		for(int i=1;i<=n;i++){
			read(ps);
			ps+=T;
			a[i]=ps;
			nxt[i]=n;
			ans[i]=b[i]=0;
		}
		l=r=1;
		while(r<=n){
			if(a[r]-a[l]<=d){
				nxt[l]=r;
				r++;
			}else{
				l++;
			}
		}
		for(int i=n;i>=1;i--){
			x=nxt[i];
			if(x==n)continue;
			y=nxt[x];
			ans[i]=ans[x];
			if(a[y-1]-a[x-1]<=d){
				ans[i]-=b[x];
			}
			if(x-i<=1)continue;
			l=x,r=y;
			k=x;
			while(l<=r){
				md=l+r>>1;
				if(a[md]-a[x-1]<=d){
					k=md;
					l=md+1;
				}else{
					r=md-1;
				}
			}
			if(k==x)continue;
			l=x,r=y;
			k1=x;
			while(l<=r){
				md=l+r>>1;
				if(a[md]-a[x-2]<=d){
					k1=md;
					l=md+1;
				}else{
					r=md-1;
				}
			}
			b[i]=k-k1;
			ans[i]+=b[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=ans[i];
		}
		print(cnt);
		putchar('\n');
	}
	return 0;
}
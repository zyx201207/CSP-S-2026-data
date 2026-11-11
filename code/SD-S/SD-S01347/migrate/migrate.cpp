#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
int a[N],sum[N],dp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		int n=read(),m=read();
		bool ok=false;
		for(int i=1;i<=n;i++) a[i]=read();
		int d=a[2]-a[1],ans=0;
		for(int i=3;i<=n && !ok;i++)
			if(a[i]-a[i-1]!=d) ok=true;
		if(!ok){
			if(d>=m) puts("0");
			else{
				for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
				for(int i=1;i<=n;i++){
					int pos=i;
					for(int j=i+1;j<=n;j++){
						if(sum[j]-sum[i-1]>m) break;
						pos=j;
					}
					ans=max(ans,i-pos+1);
				}
				write(ans);
				puts("");
			}
		}
	}
	return 0;
}


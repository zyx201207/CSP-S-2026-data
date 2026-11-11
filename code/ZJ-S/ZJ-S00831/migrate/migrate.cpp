#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1000000000000000000;
ll i,j,k,n,d,c,t,x,a[2000005],dp[1005][1005],s[1005][1005],ans;
bool f[1005][1005];
ll read() {
	ll k=0;
	ll f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x<10) {
		putchar(x+'0');
	} else {
		write(x/10);
		putchar(x%10+'0');
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--) {
		n=read();
		d=read();
		for(i=1; i<=n; i++) {
			a[i]=read();
		}
		if(c>=11&&c<=12) {
			x=a[2]-a[1];
			if(d>=2*x) {
				write(n-2);
				putchar('\n');
			} else {
				write(0);
				putchar('\n');
			}
		} else {
			for(i=1; i<=n; i++) {
				for(j=1; j<=n; j++) {
					dp[i][j]=INF;
					s[i][j]=1;
					f[i][j]=0;
				}
			}
			for(i=1; i<=n; i++) {
				for(j=i+1; j<=n; j++) {
					if(a[j]-a[i]<=d) {
						f[i][j]=1;
						f[j][i]=1;
						dp[i][j]=1;
						dp[j][i]=1;
					}
				}
			}
			for(k=1; k<=n; k++) {
				for(i=1; i<=n; i++) {
					for(j=1; j<=n; j++) {
						if(f[i][k]==1&&f[j][k]==1) {
							x=dp[i][k]+dp[k][j]+1;
							if(dp[i][j]==x) {
								s[i][j]++;
							} else {
								if(dp[i][j]>x) {
									dp[i][j]=x;
									s[i][j]=1;
								}
							}
						}
					}
				}
			}
			ans=0;
			for(i=1; i<=n; i++) {
				for(j=i+1; j<=n; j++) {
					if(s[i][j]==2) {
						ans++;
					}
				}
			}
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int T,c,n,d;
int x[2000010],way[2000010],dp[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		for(int i=1;i<=n;i++){
			way[i]=1,dp[i]=0;
			int l=i,r=i;
			bool flag=0;
			while(r<=n){
				r++;
				while(x[r]-x[l]>d&&l<=r){
					if(l==r-1){
						for(int k=r;k<=n;k++){
							dp[k]=-1;
						}
						flag=1;
						break;
					}
					l++;
				}
				if(flag){
					break;
				}
				dp[r]=dp[l]+1;
				int cnt=0;
				for(int k=l;k<=r;k++){
					if(dp[k]==dp[l]){
						cnt+=way[k];
					}
				}
				way[r]=cnt;
				if(cnt==2){
					ans++;
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
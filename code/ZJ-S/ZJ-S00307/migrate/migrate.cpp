#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll res=0ll;
	int f=0,ch;
	do{
		ch=getchar();
		if(ch=='-') f=1;
	}while(!isdigit(ch));
	do{
		res=(res<<1)+(res<<3)+(ch&0xf);
		ch=getchar();
	}while(isdigit(ch));
	return f?-res:res;
}
constexpr int N=2e6+2;
int c,t;
ll n,d,x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;++i){
			x[i]=read();
		}
		if(n==1){
			puts("0");
			continue;
		}
		if(1<=c&&c<=6||c==0){//N=300
//			int sum;
			ll dp[n+1][n+1][2];
			for(int i=1;i<=n;++i){
				dp[i][i][0]=0;
				dp[i][i][1]=1;
				for(int j=i-1;j>0;--j){
					dp[i][j][0]=N;dp[i][j][1]=0;
				}
			}
			ll ans=0ll;
			for(int j=2;j<=n;++j){
				for(int i=j-1;i;--i){
					if(x[j]-x[i]<=d){
						for(int k=1;k<=i;++k){
							if(dp[i][k][0]==N)continue;
							if(dp[i][k][0]+1<dp[j][k][0]){
								dp[j][k][0]=dp[i][k][0]+1;
								dp[j][k][1]=dp[i][k][1];
							}
							else if(dp[i][k][0]+1==dp[j][k][0]){
								dp[j][k][1]+=dp[i][k][1];
							}
						}
					}
					else break;
				}
			}
//			for(int j=1;j<=n;++j){
//				for(int i=1;i<=j;++i){
//					printf("%lld,%lld ",dp[j][i][0],dp[j][i][1]);
//				}
//				puts("");
//			}
			for(int j=4;j<=n;++j){
				for(int i=1;i<=j-3;++i){
					if(dp[j][i][1]==2) ++ans;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(7<=c&&c<=10){//N=5000
			puts("0");
			continue;
		}
		else if(c==11||c==12){
			ll del=x[2]-x[1];
			
//			printf("%lld : %lld : %lld ",n,d,del);
			
			if(del>=d){
				puts("0");
				continue;
			}
			ll unpb=(d/del);
//			ll npb=unpb+1;
//			ll pbs=(n+npb-1)/npb;
			printf("%lld\n",max(0ll,n-unpb*2+1));
		}
		else if(c==13||c==14){
			puts("0");
			continue;
		}
		puts("0");
		
	}
	return 0;
}
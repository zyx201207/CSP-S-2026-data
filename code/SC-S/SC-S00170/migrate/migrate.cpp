#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,ans;
const int N=2e6+9;
int x[N],L[N];
int f[5009][5009],g[5009][5009];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(c<=10){
			L[0]=1;
			for(int i=1;i<=n;i++){
				L[i]=L[i-1];
				while(x[i]-x[L[i]]>d)++L[i];
			}
			for(int l=1;l<=n;l++){
				g[l][l]=1;
				for(int r=l+1;r<=n;r++){
					f[l][r]=1e9+7;
					for(int i=max(L[r],l);i<r;i++){
						if(f[l][r]>f[l][i]+1)f[l][r]=f[l][i]+1,g[l][r]=g[l][i];
						else if(f[l][r]==f[l][i]+1)g[l][r]+=g[l][i];
					}
					g[l][r]=min(g[l][r],3ll);
					if(g[l][r]==2)++ans;
				}
			}
			printf("%lld\n",ans);
			ans=0;
			for(int l=1;l<=n;l++)
				for(int r=l;r<=n;r++)f[l][r]=g[l][r]=0;
		}else{
			int cnt=d/(x[2]-x[1]);
			printf("%lld\n",cnt<=1?0:max(n-2*cnt+1,0ll));
		}
	}
}
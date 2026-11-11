#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,x[N];
int f[N],g[N],sg[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			g[i]=1;
			sg[i]=1;
			for(int j=i+1;j<=n;j++){
				int l=lower_bound(x+i,x+j,x[j]-d)-x;
				if(l==j) break;
				int r=upper_bound(f+i,f+j,f[l])-f-1;
				f[j]=f[l]+1;
				g[j]=sg[r]-sg[l-1];
				sg[j]=sg[j-1]+g[j];
				if(g[j]==2) ans++;
			}
			f[i]=g[i]=sg[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

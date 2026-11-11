#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,NN=5005;
ll x[N];
int f[NN][NN],cnt[NN][NN];
int c,t;
int n,ans;
ll d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		if(c==11||c==12||c==0) {
			scanf("%d%lld",&n,&d);
			//cout<<n<<" "<<d<<" ";
			for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
			ll xd=x[2]-x[1];
			if(d<2*xd) {
				printf("0\n");
				continue;
			}
			ll z=d/xd*2;
			if(z>n) {
				printf("0\n");
				continue;
			}
			//cout<<xd<<" "<<z<<" ";
			printf("%lld\n",1ll*n-z+1);
			continue;
		}
		ans=0;
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
		for(int u=1;u<=n;++u) {
			for(int v=u+1;v<=n;++v) {
				if(x[v]-x[u]<=d) f[u][v]=f[v][u]=1,cnt[u][v]=cnt[v][u]=1;
			} 
		}
		for(int k=1;k<=n;++k) {
			for(int i=1;i<=n;++i) {
				for(int j=1;j<=n;++j) {
					if(f[i][j]==f[i][k]+f[k][j]) cnt[i][j]++,cnt[j][i]++;
					else if(f[i][j]>f[i][k]+f[k][j]) {
						f[i][j]=f[j][i]=f[i][k]+f[k][j];
						cnt[i][j]=cnt[j][i]=1;
					}
				}
			}
		}
		for(int u=1;u<=n;++u) {
			for(int v=u+1;v<=n;++v) {
				if(cnt[u][v]==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

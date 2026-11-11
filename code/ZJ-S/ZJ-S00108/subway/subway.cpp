#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5e5+6,M=506;
int c,n,m,d,q;
int ans=0;
int used=0;
int w[N];
int K[M];
vector<int>t[N],a[N];
int x[N],y[N];
int g[M][M];
int mt[M][M];
void init(){
	memset(mt,0x3f,sizeof(mt));
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++){
		mt[i][i]=0;
	}

	for(int k=1;k<=m;k++){
		for(int i=0;i<a[k].size();i++){
			for(int j=0;j<a[k].size();j++){
				if(mt[a[k][i]][a[k][j]]>t[k][i]+t[k][j])
					mt[a[k][i]][a[k][j]]=t[k][i]+t[k][j];
			}
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mt[i][j]>mt[i][k]+mt[k][j]){
					mt[i][j]=mt[i][k]+mt[k][j];
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&K[i]);
		for(int j=1;j<=K[i];j++)
		{
			int opa,opt;
			scanf("%lld%lld",&opa,&opt);
			a[opa].push_back(i);
			t[opa].push_back(opt);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	init();
	floyd();
	for(int qq=1;qq<=q;qq++){
		int xq=x[qq],yq=y[qq];
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<a[xq].size();i++){
			for(int j=0;j<a[yq].size();j++){
				if(ans>mt[a[xq][i]][a[yq][j]]+t[xq][i]+t[yq][j]){
					ans=mt[a[xq][i]][a[yq][j]]+t[xq][i]+t[yq][j];
				}
			}
		}
		printf("%lld\n",ans+w[xq]+w[yq]);
	}
	return 0;
}

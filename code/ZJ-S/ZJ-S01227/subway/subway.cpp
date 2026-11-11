#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=510;
int C,n,m,d,_,w[N],tot;
ll f[M][M];
vector<pair<int,int>> S[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>_;
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1,k;i<=n;++i){
		scanf("%d",&k);
		for(int j=1,x,t;j<=k;++j){
			scanf("%d%d",&x,&t);
			S[x].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j) f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;++i){
		for(auto [j,t1]:S[i]){
			for(auto [k,t2]:S[i]){
				f[j][k]=min(f[j][k],(ll)t1+t2);
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			printf("i=%d j=%d %lld\n",i,j,f[i][j]);
//		}
//	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(_--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(auto [i,t1]:S[x]){
			for(auto [j,t2]:S[y]){
				ans=min(ans,f[i][j]+t1+t2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
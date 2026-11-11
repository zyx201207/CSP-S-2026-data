//nb,最后一次csp依旧无法战胜第二题吗 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long f[505][505];
int w[500005];
int len[500005];
pair<int,int> a[500005][22];//a[i][j] 第i个站有哪些线 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			long long u,t;
			scanf("%lld%lld",&u,&t);
			a[u][++len[u]]={i,t}; 
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++){
			for(int k=j+1;k<=len[i];k++){
				f[a[i][j].first][a[i][k].first]=f[a[i][k].first][a[i][j].first]=min(f[a[i][k].first][a[i][j].first],1ll*a[i][j].second+a[i][k].second);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			} 
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v); 
		long long ans=1e18;
		for(int i=1;i<=len[u];i++){
			for(int j=1;j<=len[v];j++){
//				cout<<a[u][i].first<<" "<<a[v][j].first<<" "<<f[a[u][i].first][a[v][j].first]<<endl;
				ans=min(f[a[u][i].first][a[v][j].first]+a[u][i].second+a[v][j].second,ans);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}

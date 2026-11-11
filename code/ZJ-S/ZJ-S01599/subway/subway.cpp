#include<bits/stdc++.h>
#define pb push_back
#define Pair pair<int,int>
#define FF first
#define SS second
using namespace std;
const int N=510,M=5e5+10;
const long long inf=1e18;
int c,n,m,d,q,x,y,X,Y,K,W[M],T[M][N];
long long ans,f[N][N];
vector<int> a[M];
void Main(){
//	cin>>x>>y;
	scanf("%d%d",&x,&y);
	ans=inf;
	for(int i=0;i<a[x].size();i++){
		for(int j=0;j<a[y].size();j++){
			X=a[x][i];
			Y=a[y][j];
			ans=min(ans,W[x]*1ll+W[y]*1ll+T[x][X]*1ll+T[y][Y]*1ll+f[X][Y]*1ll);
		}
	}
//	cout<<ans<<"\n";
	printf("%lld\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				f[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=m;i++){
//		cin>>W[i];
		scanf("%d",&W[i]);
	}
	for(int i=1;i<=n;i++){
//		cin>>K;
		scanf("%d",&K);
		for(int j=1;j<=K;j++){
//			cin>>x;
			scanf("%d",&x);
//			cin>>T[x][i];
			scanf("%d",&T[x][i]);
			a[x].pb(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=0;k<a[i].size();k++){
				if(j!=k){
					x=a[i][j];
					y=a[i][k];
					long long tmp=T[i][x]*1ll+T[i][y]*1ll;
					f[x][y]=min(f[x][y],tmp);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		Main();
	}
	return 0;
}
/*
每个线路就是一个集合 
预处理两个集合之间的最短路
然后 floyd 可做 
400*5e5

*/

#include<bits/stdc++.h>
using namespace std;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef float f32;
typedef double f64;
typedef long double f128;
#define endl '\n'
const i64 N=505,M=5e5+10,INF=1e18;
i64 dis[N][N],w[M],ans;
i32 c,n,m,d,q,i,j,k,u,v,x,y;
vector<i32> a[M];
vector<i64> t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>u>>v;
			a[u].push_back(i);
			t[u].push_back(v);
		}
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		if(i!=j)dis[i][j]=INF;
		else dis[i][j]=0;
	}
	for(i=1;i<=m;i++)for(j=0;j<(i32)a[i].size();j++)for(k=0;k<(i32)a[i].size();k++){
		if(j==k)continue;
		dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)if(i!=k&&dis[i][k]!=INF)for(j=1;j<=n;j++)if(j!=k&&dis[k][j]!=INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y,ans=INF;
		for(i=0;i<(i32)a[x].size();i++)for(j=0;j<(i32)a[y].size();j++)ans=min(ans,t[x][i]+t[y][j]+dis[a[x][i]][a[y][j]]);
		cout<<w[x]+w[y]+ans<<endl;
	}
	return 0;
}

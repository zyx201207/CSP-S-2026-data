#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[505],t[505][50005],a[505][50005],z[50005][505],sum[50005],x,y,ans;
//sum[i]表示第i站有几条线路,z[i][j]表示第i站的第j条线路是谁,a[i][j]表示第i条线路的第j个站,t[i][j]表示第i条线路上第j站站台到站厅时间
bool vis1[500005],vis2[505];
void dfs(int now,int ti){
	if(now==y){
		ans=min(ans,ti);
		return;
	}
	for(int i=0;i<sum[now];i++){
		int lin=z[now][i];
		if(vis2[lin]){
			continue;
		}
		vis2[lin]=1;
		for(int j=1;j<=k[lin];j++){
			if(a[lin][j]==now||vis1[a[lin][j]]){
				continue;
			}
			vis1[a[lin][j]]=1;
			dfs(a[lin][j],ti+t[lin][now]+t[lin][a[lin][j]]);
			vis1[a[lin][j]]=0;
		}
		vis2[lin]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][a[i][j]]);
			z[a[i][j]][sum[a[i][j]]]=i;
			sum[a[i][j]]++;
		}
	}
	for(int i=0;i<q;i++){
		scanf("%lld%lld",&x,&y);
		ans=1e9+7;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

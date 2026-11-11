#include<bits/stdc++.h>
using namespace std;
long long c,n,m,dd,q,w[500005],k,t[500005][25],l[500005][25],x,y,d[505][505];
int main(){
	long long i,j;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		while(k--){
			long long u,v;
			cin>>u>>v;
			t[u][++t[u][0]]=v;
			l[(int)u][(int)t[u][0]]=i;
		}
	}
	memset(d,0x3f,sizeof d);
	for(i=1;i<=m;i++)for(j=1;j<=t[(int)i][0];j++)for(k=1;k<=t[(int)i][0];k++)if(j!=k)d[(int)l[(int)i][(int)j]][(int)l[(int)i][(int)k]]=min(t[(int)i][(int)j]+t[(int)i][(int)k],d[(int)l[(int)i][(int)j]][(int)l[(int)i][(int)k]]);
	for(i=1;i<=n;i++)d[i][i]=0;
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j&&i!=k&&j!=k&&d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
	while(q--){
		cin>>x>>y;
		long long res=0x3f3f3f3f3f3f3f3f;
		for(i=1;i<=t[(int)x][0];i++)for(j=1;j<=t[(int)y][0];j++)res=min(res,d[(int)l[(int)x][(int)i]][(int)l[(int)y][(int)j]]+t[(int)x][(int)i]+t[(int)y][(int)j]);
		cout<<res+w[(int)x]+w[(int)y]<<'\n';
	}
	return 0;
}

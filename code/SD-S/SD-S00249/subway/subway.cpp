#include<bits/stdc++.h>
#define int long long
#define ll long long
#define N 510
#define M 500050
using namespace std;
struct nd{
	ll pos,dis;
};
ll c,n,m,d,q,w[M],dp[N][N];
vector<nd>vt[N];
vector<nd>lj[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
//		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		scanf("%d",&k);
//		cin>>k;
		for(int j=1;j<=k;j++){
			ll x,y;
			scanf("%d%d",&x,&y);
//			cin>>x>>y;
			vt[j].push_back({x,y});
			lj[x].push_back({i,y});
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<lj[i].size();j++){
			for(int k=j+1;k<lj[i].size();k++){
				ll wei1=lj[i][j].pos,wei2=lj[i][k].pos,zhi1=lj[i][j].dis,zhi2=lj[i][k].dis;
				dp[wei1][wei2]=min(dp[wei1][wei2],zhi1+zhi2);
				dp[wei2][wei1]=dp[wei1][wei2];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		ll x,y,ans=0x3f3f3f3f3f3f;
		scanf("%d%d",&x,&y);
//		cin>>x>>y;
		for(int i=0;i<lj[x].size();i++){
			for(int j=0;j<lj[y].size();j++){
				ll wei1=lj[x][i].pos,wei2=lj[y][j].pos,zhi1=lj[y][j].dis,zhi2=lj[x][i].dis;
				ans=min(ans,zhi1+zhi2+dp[wei1][wei2]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
//

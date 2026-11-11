#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long c,n,m,d,q,a[500010],cnt[500010],w[510][510],dis[510][510];
struct node{
	long long id,x;
};
vector<node>sta[500010];
signed main(){
	ios
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(w,0x3f,sizeof w);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			sta[x].push_back(node{i,y});
			cnt[x]++;
		}
	}
	for(long long i=1;i<=n;i++)w[i][i]=0;
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<cnt[i];++j){
			for(long long k=0;k<cnt[i];++k){
				if(j==k)continue;
				long long u=sta[i][j].id,v=sta[i][k].id,nw=sta[i][j].x+sta[i][k].x;
				w[u][v]=min(w[u][v],nw);
				w[v][u]=min(w[v][u],nw);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		long long l,r;
		cin>>l>>r;
		long long ans=1e18;
		for(long long i=0;i<cnt[l];++i){
			for(long long j=0;j<cnt[r];++j){
				long long u=sta[l][i].id,v=sta[r][j].id;
				long long W=sta[l][i].x+sta[r][j].x;
				ans=min(ans,a[l]+a[r]+w[u][v]+W);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
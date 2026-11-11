#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,ans,i,j,dis[200010],sum[200010],x[200010];
queue<int>q; 
void spfa(int xx){
	int fx,sx,i,sy;
	for(int i=1;i<=n;i++) dis[i]=2e18,sum[i]=0;
	q.push(xx);dis[xx]=0;sum[xx]=1;
	while(!q.empty()){
		fx=q.front();q.pop();
		for(i=fx+1;i<=n;i++){
			sx=i;sy=x[i]-x[fx];
			if(sy>d) continue;
			if(dis[fx]+1==dis[sx]) sum[sx]+=sum[fx];
			if(dis[fx]+1<dis[sx]){
				dis[sx]=dis[fx]+1;
				sum[sx]=sum[fx];
				q.push(sx);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(i=1;i<=n;i++) cin>>x[i];
		for(i=1;i<=n;i++){
			spfa(i);
			for(j=i+1;j<=n;j++)
				if(sum[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
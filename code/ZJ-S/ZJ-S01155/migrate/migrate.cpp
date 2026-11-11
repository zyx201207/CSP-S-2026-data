#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,c,n,d,x[2000005],ans,vis[2000005],dist[2005][2005],cs[2005][2005]={0};
void dfs(ll ss,ll s,ll e,ll w){
	if(s==e){
		if(w<dist[ss][e])dist[ss][e]=w,cs[ss][e]=1;
		else if(w==dist[ss][e])cs[ss][e]++;
	}
	for(int i=1;i<=n;i++)if(abs(x[s]-x[i])<=d&&!vis[i])vis[i]=1,dfs(ss,i,e,w+1),vis[i]=0;
	return;
}int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)cin>>x[i],dist[i][i]=0;
		if(c==11||c==12){
			for(int i=4;i<=n;i+=2)if(d>=x[i/2+1]-x[1]&&d<x[i/2+2]-x[1])ans+=n-i+1;
		}else{
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=1;k<=n;k++)vis[k]=0;
					dfs(i,i,j,0);
					if(dist[i][j]!=0x3f3f3f3f&&cs[i][j]==2)ans++;
				}
			}
		}cout<<ans<<endl;
	}return 0;
}
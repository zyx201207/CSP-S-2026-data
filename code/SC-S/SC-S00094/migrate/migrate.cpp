#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define fop(i,l,r) for(int i=l;i<=r;i++)
int T,n,m,a[1000005],vis[1000005];PII dis[1000005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>T>>T;while(T--){
		cin>>n>>m;fop(i,1,n)cin>>a[i],vis[i]=0;
		a[n+1]=4e18;int ans=0;fop(i,1,n){
			queue<int>q;q.push(i);dis[i]={0,1};while(q.size()){
				int u=q.front();q.pop();
				if(dis[u].se>2)continue;
				int nx=u+1;while(a[nx]-a[u]<=m){
					if(dis[nx].fi==dis[u].fi+1&&(vis[u]==i))dis[nx].se+=dis[u].se;
					if(vis[nx]!=i)dis[nx]={dis[u].fi+1,dis[u].se},vis[nx]=i,q.push(nx);
					nx++;
				}
			}fop(j,i+1,n){
				if(vis[j]!=i)break;
				ans+=(dis[j].se==2);
			}
		}cout<<ans<<'\n';
	}return 0;
}/*
0 1
6 2
1 2 3 4 5 6


0 1
6 3
1 2 3 4 5 6
*/
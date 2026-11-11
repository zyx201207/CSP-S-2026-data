#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10,inf=1e18;
int c,t,n,k,u[N],v[N],fa[20],dis[20][20];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy)return;
	fa[fx]=fy;
}
void dfs(int x,int fa,int t){
	if(x!=t)dis[t][x]=dis[x][t]=dis[t][fa]+1;
	for(int i=1;i<n;i++){
		if(u[i]==x||v[i]==x){
			int y=u[i]+v[i]-x;
			if(y==fa)continue;
			dfs(y,x,t);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u[i]>>v[i];
		if(c<=3){
			for(int i=1;i<=n;i++)dfs(i,0,i);
			int ans=inf;
			for(int i=0;i<(1<<n);i++){
				for(int j=1;j<=n;j++)fa[j]=j;
				for(int j=1;j<n;j++){
					if(((i>>u[j]-1)&1)&&((i>>v[j]-1)&1))merge(u[j],v[j]);
				}
				int flg=0;
				for(int j=1;j<=n;j++){
					if(!((i>>j-1)&1))continue;
					if(fa[j]==j)flg++;
				}
				if(flg<=2){
					int mx=0;
					for(int j=1;j<=n;j++){
						if((i>>j-1)&1)continue;
						int mn=inf;
						for(int k=1;k<=n;k++){
							if((i>>k-1)&1)mn=min(mn,dis[j][k]);
						}
						mx=max(mx,mn);
					}
					ans=min(ans,mx);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int> bs[1000005];
int fa[1000005];
int dis[25][25];
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]);
}
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)bs[i].clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j)dis[i][j]=n;
			else dis[i][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		bs[u-1].push_back(v-1);
		bs[v-1].push_back(u-1);
		dis[u-1][v-1]=1;
		dis[v-1][u-1]=1;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=n*n;
	for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)==k){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				fa[j]=j;
			}
			else fa[i]=0;
		}
		for(int u=0;u<n;u++)if(i&(1<<u)){
			for(int v:bs[u])if(i&(1<<v)){
				if(findfa(u)!=findfa(v)){
					fa[fa[u]]=fa[v];
				}
			}
		}
		bool flag=1;
		for(int p1=0;p1<n;p1++)if(i&(1<<p1)){
			for(int p2=0;p2<n;p2++)if(i&(1<<p2)){
				for(int p3=0;p3<n;p3++)if(i&(1<<p3)){
					if(findfa(p1)!=findfa(p2) && findfa(p1)!=findfa(p3) && findfa(p2)!=findfa(p3)){
						flag=0;
					}
				}
			}
		}
		if(flag){
			int cnt=0;
			for(int u=0;u<n;u++){
				int minn=n;
				for(int v=0;v<n;v++)if(i&(1<<v))minn=min(minn,dis[u][v]);
				cnt=max(cnt,minn);
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
}

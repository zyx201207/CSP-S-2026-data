#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k[505],w[500005],dp[1505][1505],dis[500505];
vector<int> line[505],t[505],road[500505];
queue<int> Q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	if(c<=11){
		int a,b;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j) dp[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%lld %lld",&a,&b);
				line[i].push_back(a);
				t[i].push_back(b);
			}
			for(int l=0;l<k[i]-1;l++){
				for(int r=l+1;r<k[i];r++){
					dp[line[i][l]][line[i][r]]=min(dp[line[i][l]][line[i][r]],t[i][l]+t[i][r]);
				}
			}
		}
		for(int r=1;r<=m;r++){
			for(int l=1;l<=r;l++){
				for(int i=l;i<=r;i++){
					dp[l][r]=min(dp[l][r],dp[l][i]+dp[i][r]);
				}
			}
		}
		while(q--){
			int u,v;
			scanf("%lld %lld",&u,&v);
			if(u>v) swap(u,v);
			printf("%lld\n",w[u]+w[v]+dp[u][v]);
		}
	}
	else{
		int a,b,T=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%lld %lld",&a,&b);
				T=b;
				road[m+i].push_back(a);
				road[a].push_back(m+i);
			}
		}
		while(q--){
			int u,v;
			scanf("%lld %lld",&u,&v);
			Q.push(u);
			for(int i=1;i<=n+m;i++) dis[i]=1e18;
			dis[u]=0;
			while(Q.size()){
				int now=Q.front();
				Q.pop();
				for(int i=0;i<road[now].size();i++){
					int to=road[now][i];
					if(dis[to]>=1e18){
						dis[to]=dis[now]+1;
						Q.push(to);
					}
				}
			}
			printf("%lld\n",w[u]+w[v]+dis[v]*T);
		}
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,inf=3e18,base=233;
int c,n,m,d,q,W[500005],k[505],dis[505][505];
struct node{
	int x,t;
};
vector<node>g[505],fr[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int now=clock();
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			g[i].push_back({x,t});
			fr[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){//O(md)
		for(int j=0;j<g[i].size();j++){
			int u=g[i][j].x,t=g[i][j].t,len=fr[u].size();
			if(len==1)continue;
			for(int k=0;k<len;k++){
				if(fr[u][k].x==i)continue;
				dis[i][fr[u][k].x]=min(dis[i][fr[u][k].x],t+fr[u][k].t);
				dis[fr[u][k].x][i]=min(dis[fr[u][k].x][i],t+fr[u][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int s,t,ans=0,res=inf;
		cin>>s>>t;
		ans=W[s]+W[t];
		for(int i=0;i<fr[s].size();i++){
			int u=fr[s][i].x;
			for(int j=0;j<fr[t].size();j++){
				int v=fr[t][j].x;
				res=min(res,dis[u][v]+fr[s][i].t+fr[t][j].t);
			}
		}
		cout<<ans+res<<endl;
	}
}
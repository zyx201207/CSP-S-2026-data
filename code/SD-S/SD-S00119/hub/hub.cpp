#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N=105;
int c,T,n,k,d[N];
vector<int>E[N];
bool e[N][N];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	for(int v:E[u])if(v^fa)dfs(v,u);
}
int dis(int a,int b){
	if(d[a]<d[b])swap(a,b);
	int rs=0;
	while(d[a]!=d[b])a=fa[a],rs++;
	while(a!=b)a=fa[a],b=fa[b],rs+=2;
	return rs;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(e,0,sizeof e);
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;e[u][v]=1;
		}
		int ans=2e9;
		for(int S=0;S<(1<<n);S++){
			int cnt=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
				if(((S>>i-1)&1)&&((S>>j-1)&1))cnt+=e[i][j];
			if(cnt<n-2)continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int rs=2e9;
				for(int j=1;j<=n;j++)if((S>>j-1)&1)rs=min(rs,dis(i,j));
				res=max(res,rs);
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}


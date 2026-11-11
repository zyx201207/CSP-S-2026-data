#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f;
int c,n,m,d,q;
int w[N],k,a[N],t[505][505],s[N],e[N],g[505][505],cnt[N],line[505][505],vis[N],v[505];
int fa[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >qu; 
int bfs(int s,int e){
	int ans;
	qu.push({0,s});
	while(!qu.empty()){
		int st=qu.top().second;
		ans+=qu.top().first;
		if(vis[st]){
			return ans+t[e][st];
		}
		qu.pop();
		for(int i=1;i<=n;i++){
			if(g[i][st]!=INF&&!v[st]){
				qu.push({g[i][st],i});
				v[st]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		fa[i]=i;
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[j]);
			scanf("%d",&t[a[j]][i]);
			line[a[j]][++cnt[a[j]]]=i;
			if(cnt[a[j]]>1){
				for(int d=1;d<cnt[a[j]];d++){
					g[line[a[j]][d]][i]=min(g[line[a[j]][d]][i],t[a[j]][i]+t[a[j]][line[a[j]][d]]);
					g[i][line[a[j]][d]]=g[line[a[j]][d]][i];
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int ans=INF;
		scanf("%d%d",&s[i],&e[i]);
		for(int z=1;z<=cnt[e[i]];z++){
			vis[line[e[i]][z]]=1;
		}
		for(int z=1;z<=cnt[s[i]];z++){
			ans=min(ans,bfs(line[s[i]][z],e[i])+t[s[i]][line[s[i]][z]]);
			printf("");
		}
		printf("%d\n",ans+w[s[i]]+w[e[i]]);
	}
	return 0;
}

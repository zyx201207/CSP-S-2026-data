#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a,b,d[25][25],p[25];
vector<int>e[1000010];
void dfs(int i,int fa,int k){for(int w:e[i])if(w!=fa)d[k][w]=d[k][i]+1,dfs(w,i,k);}
int find(int i){return (p[i]==i)?i:p[i]=find(p[i]);}
void merge(int a,int b){a=find(a),b=find(b);if(a!=b)p[a]=b;}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int w=1;w<n;w++)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
		int ans=1e9;
		for(int w=1;w<=n;w++)for(int x=1;x<=n;x++)d[w][x]=0;
		for(int w=1;w<=n;w++)dfs(w,0,w);
		for(int w=0;w<(1<<n);w++){
			int cnt=0;
			for(int x=0;w>>x;x++)if(w>>x&1)cnt++,p[x+1]=x+1;
			if(cnt!=k)continue;
			cnt=0;
			for(int x=0;w>>x;x++)if(w>>x&1)for(int y=x+1;w>>y;y++)if((w>>y&1)&&d[x+1][y+1]==1)merge(x+1,y+1);
			for(int x=0;w>>x;x++)if((w>>x&1)&&p[x+1]==x+1)cnt++;
			if(cnt>2)continue;
			cnt=0;
			for(int x=1;x<=n;x++){int m=1e9;for(int y=0;w>>y;y++)if(w>>y&1)m=min(m,d[x][y+1]);cnt=max(cnt,m);}
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
		for(int w=1;w<=n;w++)e[w].clear();
	}
	return 0;
}

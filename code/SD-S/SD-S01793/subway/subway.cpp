#include<bits/stdc++.h>
#define maxm 100005
#define maxq 100005
struct stat{
	int id,t;
};
struct trip{
	int s,e;
};
using namespace std;
int c,n,m,d,q;
int ans;
int w[maxm];
trip r[maxq];
vector<stat>g[505];
void dfs(int s,int e,int anss){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;j++){
			int x,xt;
			scanf("%d%d",&x,&xt);
			g[i].push_back({x,xt});
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		dfs(s,e,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

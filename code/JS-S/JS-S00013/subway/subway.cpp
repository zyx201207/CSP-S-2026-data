#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const int Maxn=1e9+7;
int c,n,m,d,q,minn;
int w[M];
struct node{
	int u,t;
};
vector<node> a[N];
vector<int> pasby[M];
bool vis[N];
void dfs(int nowa,int sta,int des,int sum){
	if(nowa==des){
		minn=min(minn,sum+w[sta]+w[des]);
		return;
	}
	for(int ne:pasby[nowa]){
		if(vis[ne]==1) continue;
		vis[ne]=1;
		int nowat;
		for(node v:a[ne]) if(v.u==nowa) nowat=v.t;
		for(node v:a[ne]){
			if(v.u==nowa) continue;
			bool fla=0;
			for(int nowi:pasby[v.u]){
				if(vis[nowi]==1&&nowi!=ne){
					fla=1;
					break;
				}
			}
			if(fla==1) continue;
			int nowvt=v.t;
			dfs(v.u,sta,des,sum+nowat+nowvt);
		}
		vis[ne]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,x,y;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			a[i].push_back({x,y});
			pasby[x].push_back(i);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++) vis[i]=0;
		minn=Maxn;
		dfs(x,x,y,0);
		printf("%d\n",minn);
	}
	return 0;
}

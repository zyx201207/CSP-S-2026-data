#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int line,st;
};
struct point{
	int st,line,dis;
	bool operator<(const point& cp)const{
		return dis<cp.dis;
	}
};
int c,n,m,d,q,w[505],kk[505];
int s,e,g[500005][505];
long long ans;
bool vis[500005];
vector<int>line[505];
void solve(){
	ans=w[s]*w[e];
	memset(vis,0,sizeof vis);
	priority_queue<point>q;
	for(int i=1;i<=n;i++){
		if(g[s][i]!=0x3f3f3f3f)q.push((point){s,i,w[s]});
	}
	vis[s]=1;
	while(q.size()){
		point p=q.top();
		q.pop();
		vis[p.st]=0;
		if(p.st==e){
			ans=p.dis+g[p.st][p.line]+w[p.st];
			return;
		}
		for(int i=1;i<=m;i++){
			if(g[m][p.line]!=0x3f3f3f3f&&!vis[i]){
				vis[i]=1;
				for(int j=1;j<=n;j++){
					if(g[m][j]!=0x3f3f3f3f&&j!=p.line){
						q.push((point){m,j,p.dis+g[m][p.line]+g[m][j]});
					}
				}
			}
		}
	}
}
int main(){
	memset(g,0x3f,sizeof g);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&kk[i]);
		for(int j=1;j<=kk[i];j++){
			scanf("%d %d",&s,&e);
			line[i].push_back(s);
			g[s][i]=e;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&s,&e);
		solve();
		printf("%d\n",ans);
	}
	return 0;
}

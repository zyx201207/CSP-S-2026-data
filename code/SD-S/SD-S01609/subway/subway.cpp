#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,p,w[500005],t[500005],vis[500005];
vector <pair<int,int> > a[500005];
void bfs(){
	queue<int> q;
	q.push(1);
	t[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i].first;
			int z=a[x][i].second;
			if(t[y]>t[x]+z){
				t[y]=t[x]+z;
			}
			if(vis[y]!=1){
				t[y]=t[x]+z;
				vis[y]=1;
				q.push(y);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	bfs();
	while(p--){
		int g,k;
		scanf("%d%d",&g,&k);
		printf("%d\n",w[g]+w[k]+t[k]);
	}
	return 0;
}

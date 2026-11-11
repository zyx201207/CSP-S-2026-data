#include<bits/stdc++.h>
using namespace std;
#define LL long long
int c,n,m,d,q;
int w[500010];
struct node{
	int a,t;
	node(int x,int y):a(x),t(y) {}
};
struct node2{
	int i,w;
	node2(int x,int y):i(x),w(y){}
	bool operator <(const node2 x)const{
		return x.w<w;
	}
};
vector<node>a[550];
int k[550];
vector<int>cnt[550];
bool cmp(node x,node y){
	return x.a<y.a;
}
int dis[500010],vis[500010];
void dist(int s){
	dis[s]=0;
	priority_queue<node2>q;
	q.push(node2(s,0));
	while(!q.empty()){
		int x=q.top().i;
		q.pop();
		if(vis[x]==1){
			continue;
		}
		vis[x]=1;
		for(int i=0;i<=cnt[x].size();i++){
			int f=cnt[x][i];
			int z;
			for(int j=1;j<=k[f];j++){
				if(a[f][j].a==x){
					z=j;
				}
			}
			for(int j=1;j<=k[f];j++){
				if(a[f][j].a==x){
					continue;
				}
				int y=a[f][j].a;
				int t=a[f][j].t;
				if(dis[y]>dis[x]+a[f][z].t+a[f][j].t){
					dis[y]=dis[x]+a[f][z].t+a[f][j].t;
					if(vis[y]==0){
						q.push(node2(y,dis[y]));
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(node(x,y));
			cnt[x].push_back(i);
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dist(x);
		cout<<dis[y]<<endl;
	}
	return 0;
}


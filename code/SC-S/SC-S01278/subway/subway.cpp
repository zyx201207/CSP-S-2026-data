#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e4+5;
int C_,n,m,DD_,q;
int val[N];
int k[N],a[N][505],t[N][505],vt[N][505];
vector<int> vr[N];
bool vis[N][505];
ll dis[N][505];

struct node{
	int x,id;
	ll d;
};

bool operator<(node A,node B){
	return A.d>B.d;
}

int DIJ(int s,int t){
	priority_queue<node> q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) vis[i][j]=0,dis[i][j]=2e9;
	while(!q.empty()) q.pop();
	for(int uid:vr[s])
		q.push({s,uid,vt[s][uid]}),dis[s][uid]=vt[s][uid];
	while(!q.empty()){
		auto [x,id,d]=q.top(); q.pop();
		vis[x][id]=1;
		if(x==t) continue;
		for(int i=1;i<=k[id];i++){
			int y=a[id][i];
			for(int uid:vr[y]){
				if(!vis[y][uid] && dis[y][uid]>dis[x][id]+vt[y][id]+vt[y][uid]){
					dis[y][uid]=dis[x][id]+vt[y][id]+vt[y][uid];
					q.push({y,uid,dis[y][uid]});
				}
			}
		}
	}
	ll rs=2e9;
	for(int i=1;i<=n;i++) rs=min(rs,dis[t][i]-vt[t][i]);
	return rs;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway5.in","r",stdin);
//	freopen("my.out","w",stdout);
//	system("fc my.out subway5.ans");
	scanf("%d%d%d%d%d",&C_,&n,&m,&DD_,&q);
	for(int i=1;i<=m;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]),
			vr[a[i][j]].push_back(i),vt[a[i][j]][i]=t[i][j];
	}
	while(q--){
		int s,t; scanf("%d%d",&s,&t);
		ll ans=DIJ(s,t);
		ans+=val[s]+val[t];
		printf("%lld\n",ans);
	}
	return 0;
}

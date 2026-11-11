#include<bits/stdc++.h>
#define ll long long
#define pli pair< ll,int > 
using namespace std;
int c,n,m,d,p,head[500005+505],cnt,k,a,x[100005],y[100005],ma,xus;
ll w[500005],t,dis[500005+505],ans[100005];
bool vis[500005+505];
map< int,int >mp;
struct node{
	int ne,to;
	ll dis;
}edge[500005*20*2];
void jb(int from,int to,ll d){
	cnt++;
	edge[cnt].ne=head[from];
	edge[cnt].to=to;
	edge[cnt].dis=d;
	head[from]=cnt;
	return ;
}
void dijkstra(int s){
	for(int i=1;i<=m+n;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<pli,vector<pli>,greater<pli> >q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int hx=q.top().second;
		q.pop();
		if(vis[hx]) continue;
		vis[hx]=1;
		for(int i=head[hx];i;i=edge[i].ne){
			int y=edge[i].to;
			ll d=edge[i].dis;
			if(dis[y]>dis[hx]+d){
				dis[y]=dis[hx]+d;
				q.push(make_pair(dis[y],y));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&a,&t);
			jb(m+i,a,t);
			jb(a,m+i,t);
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]>y[i]) swap(x[i],y[i]);
		mp[x[i]]++,mp[y[i]]++;
	}
	while(1){
		ma=0;
		for(auto it : mp){
			if(it.second>ma){
				ma=it.second;
				xus=it.first;
			}
		}
		dijkstra(xus);
		bool flag=1;
		for(int i=1;i<=p;i++){
			if(ans[i]) continue;
			if(x[i]==xus){
				ans[i]=dis[y[i]]+w[x[i]]+w[y[i]];
				mp[x[i]]--,mp[y[i]]--;
			}
			if(y[i]==xus){
				ans[i]=dis[x[i]]+w[x[i]]+w[y[i]];
				mp[x[i]]--,mp[y[i]]--;
			}
			if(!ans[i]) flag=0;
		}
		if(flag) break;
	}
	for(int i=1;i<=p;i++) printf("%lld\n",ans[i]);
	return 0;
}
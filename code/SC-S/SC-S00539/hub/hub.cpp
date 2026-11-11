#include<bits/stdc++.h>
using namespace std;
#define limit 10000
int c,t;
int n,K;
struct node{
	int p;
	int st;
};
vector<int> vt[1001];
int dis[1000][1000];
queue<node> q;
void bfs(int bg){
	while(!q.empty())q.pop();
	memset(dis,-1,sizeof dis);
	q.push({bg,0});
	dis[bg][bg]=0;
	while(!q.empty()){
		int now=q.front().p;
		int s=q.front().st;
		q.pop();
		for(int i:vt[now]){
			if(dis[bg][i]!=-1)continue;
			q.push({i,s+1});
			if(dis[bg][i]==-1)dis[bg][i]=s+1;
		}
	}
}
int o[1001];
int vis[1001];//1：bfs走过   -1：被标记  0：区域外
queue<int> q1;
void bfs2(int bg){
	while(!q1.empty())q1.pop();
	q1.push(bg);
	vis[bg]=1;
	while(!q1.empty()){
		int now=q1.front();
		q1.pop();
		for(int i:vt[now]){
			if(vis[i]==1)continue;
			if(vis[i]==0)continue;
			vis[i]=1;
			q1.push(i);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>K;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		for(int i=1;i<=n;i++)bfs(i);
		for(int i=1;i<=n;i++)o[i]=i;
		int out=0x3f3f3f3f;
		for(int sd=1;sd<=limit;sd++){
			random_shuffle(o+1,o+1+n);
			memset(vis,0,sizeof vis);
			for(int i=1;i<=K;i++)vis[o[i]]=-1;
			int num=0;
			for(int i=1;i<=K;i++){
				if(vis[o[i]]!=1){
					num++;
					bfs2(o[i]);
				}
			}
			if(num>2)continue;
			cout<<"K";
			int ans=0;
			for(int i=1;i<=n;i++){
				int ad=0x3f3f3f3f;
				for(int j=1;j<=K;j++){
					if(i==o[j])ad=min(ad,0);
					ad=min(dis[i][o[j]],ad);
				}
				ans=max(ad,ans);
			}
			out=min(out,ans);
		}
		cout<<out<<"\n";
	}
	return 0;
}
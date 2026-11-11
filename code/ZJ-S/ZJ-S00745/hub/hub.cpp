#include<bits/stdc++.h>
using namespace std;
int c,t; vector<int> g[1000005];
int dis[1000005];
int fa[1000005];
bool f[1000005];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int tq=q.front();q.pop();
		for(int v:g[tq]){
			if(dis[tq]+1<dis[v]){
				dis[v]=dis[tq]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1e7;
		for(int bit=0;bit<(1<<n);bit++){
			vector<int> t;
			int cnt=0;
			for(int i=1;i<=n;i++){
				f[i]=0;
				if((bit>>(i-1))&1){
					cnt++;
					f[i]=1;
					t.push_back(i);
					fa[i]=i;
				}
			}
			if(cnt!=k)continue;
			for(int i=0;i<t.size();i++){
				int u=t[i];
				for(int v:g[u]){
					if(f[v]==0)continue;
					int fu=find(u);
					int fv=find(v);
					if(fu!=fv){
						fa[fu]=fv;
					}
				}
			}
			cnt=0;int id1=0,id2=0;
			bool ke=1;
			for(int i:t){
				int ff=find(i);
				if(cnt==0){
					cnt++;
					id1=ff;
				}else if(cnt==1&&ff!=id1){
					cnt++;
					id2=ff;
				}else if(cnt==2&&ff!=id1&&ff!=id2){
					ke=0;
					break;
				}
			}
			if(ke==0)continue;
			int maxx=0;
			for(int i=1;i<=n;i++){
				if(f[i])continue;
				int minn=1e7;
				for(int j=1;j<=n;j++){
					dis[j]=1e7;
				}
				dis[i]=0;
				bfs(i);
				for(int j:t){
					minn=min(minn,dis[j]);
				}
				maxx=max(maxx,minn);
			}
//			if(maxx==1){
//				for(int j:t){
//					cout<<j<<" ";
//				}
//				cout<<"\n\n\n";
//			}
			ans=min(ans,maxx);
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10



0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/
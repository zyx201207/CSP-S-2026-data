#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 20005;

ll T,w[M],c,n,m,k,d,dis[15][15],ans;
bool vis[25],state[30];
vector<int> edge[25];
void dij(int st){
	memset(vis,0,sizeof(vis));
	priority_queue< pair<int,int> > pq;
	dis[st][st]=0;
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		pair<int,int> t=pq.top();
		pq.pop();
		int w = t.first,u = t.second;
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(int j=0;j<edge[u].size();j++){
			int i = edge[u][j];
			if(dis[st][i]>1+w){
                dis[st][i]=1+w;
                //cout<<u<<" "<<i.v<<" "<<dis[i.v]<<endl;
                pq.push(make_pair(dis[st][i],i));
			}
		}
	}
}
bool check(vector<int> g){
	//cout<<1<<endl;
	int cnt=0;
	bool fl[200];
	memset(fl,0,sizeof(fl));
	for(int i=0;i<g.size();i++){
		if(fl[g[i]]==0){
			cnt++;
			fl[g[i]]=1;
		}
		for(int k=0;k<edge[g[i]].size();k++){
			fl[edge[g[i]][k]]=1;
		}
	}
	return (cnt<=2?0:1);
}
void dfs(int cur,int used){
	if(cur==n){
		if(used==k){
			ll sum=0;
			vector<int> aa;
			for(int i=1;i<=n;i++)
			{
				//cout<<state[i]<<" ";
				if(state[i]==1){
					aa.push_back(i);
				}
			}
			if(check(aa)) {
				return ;
			}
			for(int i=1;i<=n;i++)
			{
				if(state[i]==0){
					ll t=0x7f7f;
					for(int j=0;j<aa.size();j++){
						t = min(dis[i][aa[j]],t);
					}
					sum=max(sum,t);
				}
			}
			//cout<<sum<<endl;
			ans = min(sum,ans);
		}
		return ;
	}
	state[cur+1]=1;
	dfs(cur+1,used+1);
	state[cur+1]=0;
	dfs(cur+1,used);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int t;
	cin>>c>>t;
	
	while(t--){
		for(int i=0;i<=24;i++){
            edge[i].clear();
        }
		ans=0x7f7f;
		memset(dis,0x7f,sizeof(dis));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			dij(i);
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		state[1]=1;
		dfs(1,1);
		state[1]=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
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
*/


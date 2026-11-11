#include<bits/stdc++.h>
using namespace std;
void solve1(){
	int n,k;
	cin>>n>>k;
	vector< vector<int> > adj(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int ans=0x3f3f3f3f;
	for(int msk=0;msk<((1<<n)-1);msk++){
		if(__builtin_popcount(msk)!=k)continue;
		//cout<<msk<<"msk\n";
		vector<int> dis(n+1,-1);
		queue<int> q,q2;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(msk&(1<<i)){
				if(dis[i]==-1){
					cnt++;
					q.push(i);
					q2.push(i);
					//cout<<i<<" "<<cnt<<"R\n";
					dis[i]=0;
					while(!q.empty()){
						int now=q.front();
						q.pop();
						for(int to:adj[now]){
							if((msk&(1<<to))&&dis[to]==-1){
								//cout<<to<<"R\n";
								q.push(to);
								q2.push(to);
								dis[to]=0;
							}
						}
					}
				}
			}
		}
		//cout<<cnt<<"cnt\n";
		if(cnt>2)continue;
		int maxdis=-0x3f3f3f3f;
		while(!q2.empty()){
			int now=q2.front();
			q2.pop();
			maxdis=max(maxdis,dis[now]);
			for(int to:adj[now]){
				if(dis[to]==-1){
					q2.push(to);
					dis[to]=dis[now]+1;
				}
			}
		}
		ans=min(ans,maxdis);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(1<=c&&c<=3){
		while(t--){
			solve1();
		}
	}
	/*
	else if(c==7||c==11||c==12){
		while(t--){
			int n,k;
			cin>>n>>k;
			vector< vector<int> > adj(n);
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				adj[u-1].push_back(v-1);
				adj[v-1].push_back(u-1);
			}
			vector<int> dep(n);
			queue<int> q;
			q.push_back(0);
			
		}
	}
	*/
	return 0;
}

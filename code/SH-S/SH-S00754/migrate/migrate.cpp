#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
long long x[5005],d[5005],cnt[5005];
vector<int> adj[5005];
const long long INF=1e18;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,di;
		cin>>n>>di;
		long long ans=0;
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>x[i];
			d[i]=INF;
			cnt[i]=0;
			for(int j=0;j<i;j++){
				if(x[i]-x[j]<=di){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		for(int i=0;i<n;i++){
			queue<int> q;
			for(int j=0;j<n;j++){
				d[j]=INF;
				cnt[j]=0;
			} 
			d[i]=0;
			q.push(i);
			while(!q.empty()){
				int node=q.front();
				q.pop();
				for(auto next:adj[node]){
					if(d[next]==d[node]+1){
						cnt[next]++;
					}
					else if(d[next]>d[node]+1){
						d[next]=d[node]+1;
						cnt[next]=1;
						q.push(next);
					}
				}
			}
			for(int j=i+1;j<n;j++){
				if(cnt[j]==2){
					//cout<<i<<" "<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

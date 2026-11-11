#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,front,rear,q[1000011],o[1000011],ans=(1<<30);
vector<int> edges[1000011],edges1[1000011];
bool ok[1000011],ok1[1000011];
void dfs1(int p){
	ok1[p]=1;
	for(auto i:edges[p]){
		if(ok1[i]==0){
			dfs1(i);
		}
	}
}
void dfs(int p,int sum){
	if(p>n){
		for(int i=1;i<=n;i++){
			edges1[i].clear();
			if(ok[i]==1){
				for(auto j:edges[i]){
					if(ok[j]==1){
						edges1[i].push_back(ok[i]);
					}
				}				
			}
		}
		for(int i=1;i<=n;i++){
			ok1[i]=0;
		}
		int sum1=0;
		for(int i=1;i<=n;i++){
			if(ok[i]==1&&ok1[i]==0){
				sum1++;
				dfs1(i);
			}
			if(sum1>2){
				break;
			}
		}
		if(sum1<=2){
			for(int i=1;i<=n;i++){
				ok1[i]=0;
			}
			front=1,rear=0;
			for(int i=1;i<=n;i++){
				if(ok[i]==1){
					ok1[i]=1;
					q[++rear]=i;
					o[i]=0;
				}
			}
			while(front<=rear){
				int p=q[front++];
				for(auto i:edges[p]){
					if(ok1[i]==0){
						q[++rear]=i;
						o[i]=o[p]+1;
						ok1[i]=1;
					}
				}
			}
			int ma=0;
			for(int i=1;i<=n;i++){
				ma=max(ma,o[i]);
			}
			ans=min(ans,ma);
		}
	}
	if(sum+(n-p)>=k){
		ok[p]=0;
		dfs(p+1,sum);
	}
	if(sum<k){
		ok[p]=1;
		dfs(p+1,sum+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=(1<<30);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			edges[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
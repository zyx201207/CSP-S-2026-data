#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
vector<int>e[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d&&i!=j){
					e[i].push_back(j);
				}
			}
		}
		long long cnt=0; 
		for(int i=1;i<=n;i++){
			vector<long long>dis(n+1,0),ans(n+1,0);
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
			}
			dis[i]=0;
			queue<long long>q;
			q.push(i);
			while(q.size()){
				auto x=q.front();
				q.pop();
				int u=x;
				for(auto v:e[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						ans[v]=0;
						q.push(v);
					}
					if(dis[v]==dis[u]+1){
						ans[v]++;
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(i>j) continue;
				cnt+=(ans[j]==2);
			}
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
} 

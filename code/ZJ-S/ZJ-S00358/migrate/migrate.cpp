#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		int n,D;
		cin>>n>>D;
		vector<int>a(n+1,0);
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<pair<int,int>>q;
			vector<pair<int,int>>dist(n+1,{1e18,0});
			q.push({i,0});
			while(!q.empty()){
				pair<int,int>tmp=q.front();
				q.pop();
				for(int j=tmp.first+1;j<=n&&a[j]-a[tmp.first]<=D;j++){
					if(dist[j].first>tmp.second+1){
						dist[j].first=tmp.second+1;
						dist[j].second=1;
						q.push({j,dist[j].first});
					}else if(dist[j].first==tmp.second+1){
						dist[j].second++;
						q.push({j,dist[j].first});
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				ans+=(dist[j].second==2);
			}
		}
		cout<<ans<<endl;
	}
}

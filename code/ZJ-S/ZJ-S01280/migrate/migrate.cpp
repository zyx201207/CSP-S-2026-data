#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int n;
long long d;
int bfs(int s,int e) {
	int ans=2e6;
	int cnt=0;
	queue<pair<int,int>>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first;
		int du=q.front().second;
		q.pop();
		if(du>ans)continue;
		if(u==e){
			if(ans>du){
				ans=du;
				cnt=1;
			}else if(ans==du){
				cnt++;
			}
			continue;
		}
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[u]<=d){
				q.push({v,du+1});
			}
		}
	}
	return cnt==2;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+3;j<=n;j++){
				ans+=bfs(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

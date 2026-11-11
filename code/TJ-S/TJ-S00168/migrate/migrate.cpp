#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,lo;
};
const int N=2e6+10;
long long a[N];
long long n,d;
vector<node> g[N];
int bfs(int x,int y){
	int ans=0,mn=INT_MAX;
	queue<node> q;
	q.push({x,0});
	while(q.size()){
		node u=q.front();
		if(u.id==y){
			if(u.lo<mn){
				mn=u.lo;
				ans=1;
			}else if(u.lo==mn)ans++;
			q.pop();
			continue;
		}
		q.pop();
		for(int v=0;v<g[u.id].size();v++){
			if(g[u.id][v].id<=y)q.push({g[u.id][v].id,u.lo+1});
		}
	}
	return ans;
}
void solve(){
	int ans1=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)g[i].push_back({j,1});
			else break;
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
			if(bfs(i,j)==2) ans1++;
		}
	}
	cout<<ans1<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

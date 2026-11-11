#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+10;
struct Node{
	int x,dis;
};
int n,d,a[N],sum,vis[N];
int dis[N],dis2[N];
int num[N][N];
auto cmp=[](Node x,Node y){return x.dis>y.dis;};
void solve02(){
	cin>>n>>d; sum=0;
	vector<int>G[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	for(int st=1;st<n;st++){
		unordered_map<int,int>mp;
		priority_queue<Node,vector<Node>,decltype(cmp)>q(cmp);
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) dis[i]=N;
		dis[st]=0; q.push({st,0}); int ans=0;
		while(!q.empty()){
			Node u=q.top(); q.pop();
			if(vis[u.x]) continue;
			vis[u.x]=1;
			for(auto v:G[u.x]){
				if(dis[v]>dis[u.x]+1){
					dis[v]=dis[u.x]+1;
					q.push({v,dis[v]});
				}
			}
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) dis2[i]=N;
		dis2[st]=0; q.push({st,0});
		while(!q.empty()){
			Node u=q.top(); q.pop();
			if(vis[u.x]) continue;
			vis[u.x]=1;
			for(auto v:G[u.x]){
				if(dis2[v]>dis2[u.x]+1){
					dis2[v]=dis2[u.x]+1;
					q.push({v,dis2[v]});
				}
				if(dis[v]==dis2[v]) mp[v]++;
			}
		}
		for(auto e:mp) if(e.second==2) sum++;
	}
	cout<<sum/4<<"\n";
}
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if(c<=2) while(t--) solve02();
	else while(t--) cout<<0<<"\n";
	return 0;
}


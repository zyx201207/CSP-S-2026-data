#include<bits/stdc++.h>
#define PII pair<ll,ll>
#define ll long long
using namespace std;
const int N=2e6;
ll n,a[N],d,ans=0;
vector<ll>dis,vis; 
vector<ll>way[N];
void bfs(int x){
	queue<PII>q;
	q.push({x,0});
	while(q.size()){
		ll node=q.front().first,sum=q.front().second;q.pop();
		if(dis[node]>sum){
			dis[node]=sum;
			vis[node]=1;
		}else if(dis[node]==sum){
			vis[node]++;
//			continue;
		}else{
			continue;
		}
		for(int i=node+1;i<=n;i++){
			if(a[i]-a[node]<=d){
				q.push({i,sum+1});
			}else{
				break;
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		way[i]=*(new vector<ll>);
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				way[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis=vis=*(new vector<ll>);
		dis.resize(n+10,1e9);
		vis.resize(n+10);
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(vis[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
}


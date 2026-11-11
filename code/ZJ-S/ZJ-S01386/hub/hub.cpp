#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define print(a)cout<<#a<<"= "<<a<<"\n";
#define aprint(a,l,r)cout<<#a<<"= ";rep(i,l,r)cout<<a[i]<<", ";cout<<"\n";
using namespace std;
typedef long long ll;
const int N=1e6+7;
ll c,T,n,k;
vector<int>e[N];
int mark[N],vis[N],dist[N];
int ans=1e9;
void dfs(int x,int f){
	vis[x]=1;
	for(auto y:e[x]){
		if(f==y)continue;
		if(mark[y])
		dfs(y,x);
	}
} 
void check(){
	rep(i,1,n)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(mark[i]&&!vis[i]){
			//cout<<i<<",";
			cnt++;
			dfs(i,0);
		}
	}
	//cout<<endl;
	//if(mark[2]&&mark[3]&&mark[9])cout<<cnt<<endl;
	if(cnt>2)return;
	rep(i,1,n)vis[i]=0;
	queue<int>q;
	rep(i,1,n){
		if(mark[i]){
			q.push(i);
			dist[i]=0;
			vis[i]=1;
		}
	}
	int res=0;
	while(q.size()){
		int x=q.front();q.pop();
		for(auto y:e[x]){
			if(!vis[y]){
				vis[y]=1;
				dist[y]=dist[x]+1;
				res=max(res,dist[y]);
				q.push(y);
			}
		}
	}
	ans=min(ans,res);
}
void DFS(int now,int x){
	if(x==k){
		check();
		return ;
	}
	for(int i=now;i<=n;i++){
		mark[i]=1;
		DFS(i+1,x+1);
		mark[i]=0;
	}
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	DFS(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
froepen
chzx_AT AK NGOI!!!!!
*/
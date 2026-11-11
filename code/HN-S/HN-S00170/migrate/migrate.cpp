#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int n,d;
int a[N];
int in[N];
ll cnt[N];
int dis[N];
queue<int> q;
vector<int> G[N];
void bfs(int s){
	while(!q.empty()) q.pop();
	cnt[s]=1, dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(dis[v]!=-1){
				if(dis[u]+1==dis[v]){
					q.push(v);
					cnt[v]+=cnt[u];
				}else continue;
			}else{
				cnt[v]+=cnt[u];
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
void BF(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				G[i].push_back(j);
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cnt[j]=0;
		for(int j=1;j<=n;j++) dis[j]=-1;
		bfs(i);
		for(int j=i+1;j<=n;j++) ans+=(cnt[j]==2);
	}
	cout<<ans<<endl;
	return ;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c,T=1; cin>>c>>T;
	while(T--) BF();
	return 0;
}  
/*
0 2
 4 2
 1 2 3 4

 5 2
 1 2 3 4 5
*/

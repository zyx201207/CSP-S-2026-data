#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000010;

int n,d,far[maxn],ans,dis[maxn],mi[maxn];
vector<int>v[maxn];
void add_edge(int x,int y){
	v[x].push_back(y);
	v[y].push_back(x);
	return ;
}
void dfs(int u,int fa,int t,int start){
	if(t<min[u]){
		min[u]=t;
	}
	for(int i=0;i<v[i].size();i++){
		int to=v[u][i];
		if(to==fa){
			continue;
		}
		dfs(to,u,t+1);
	}
	return ;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>far[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(far[j]-far[i]<=d){
				add_edge(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,0,i);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate1.in","r",stdin);
	/*freopen("migrate.out","w",stdout);*/
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	} 
	return 0;
} 

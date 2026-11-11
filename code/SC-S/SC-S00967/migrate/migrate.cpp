#include<bits/stdc++.h>
#include<windows.h>
//#define int long long
using namespace std;
int ans=INT_MAX;
int cnt=0;
vector<int> G[2000006];
void minpath(int u,int v,int dis){
	if(u==v){
		ans=min(ans,dis);
		return ;
	}
	for(int i=0;i<G[u].size();i++){
		minpath(G[u][i],v,dis+1);
	}
}
void path(int u,int v,int k,int dis){
	if(dis>k) return ;
	if(u==v){
		cnt++;
		return ;
	}
	for(int i=0;i<G[u].size();i++){
		path(G[u][i],v,k,dis+1);
	}
}
//signed main() {
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int X[n+5];
		memset(G,0,sizeof(G));
		for(int i=1;i<=n;i++){
			cin>>X[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((X[j]-X[i])<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=INT_MAX;
				cnt=0;
				minpath(i,j,0);
				path(i,j,ans,0);
				if(cnt==2) sum++; 
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
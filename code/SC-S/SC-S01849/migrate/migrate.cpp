#include<bits/stdc++.h>
using namespace std;
int n,a[200005],t,c,d;
vector<int> e[200005];
int dis[200005],wss[200005];
void dfs(int x,int d){
	if(dis[x]==d) wss[x]++;
	else if(dis[x]>d) dis[x]=d,wss[x]=1;
	for(int v:e[x]){
		dfs(v,d+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=200005;i++) e[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) e[i].push_back(j);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof(dis)),memset(wss,0,sizeof(wss));
			dfs(i,1);
			for(int i=1;i<=n;i++){
				if(wss[i]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
}
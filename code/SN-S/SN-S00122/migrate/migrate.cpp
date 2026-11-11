#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
int c,t;
int n,d,ans;
int x[200001];
int mind=inf;
int cnt;
void dfs(int u,int v,int dis){
	if(u==v&&dis==mind){
		cnt++;
		return;
	}
	if(u==v&&dis<mind){
		cnt=1;
		mind=dis;
		return;
	}
	if(dis>mind){
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(i<=v&&x[i]-x[u]<=d){
			dfs(i,v,dis+1);
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int u=1;u<n-1;u++){
			for(int v=u+2;v<=n;v++){
				cnt=0;
				mind=inf;
				dfs(u,v,0);
				if(mind!=inf&&cnt==2){
					ans++;
					//cout<<u<<' '<<v<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			x[i]=0;
		}
	}
	return 0;
}
//T3 8 pts
/*
I'd rather write large simulation
I don't like this
let me see whether I can get some points.
*/

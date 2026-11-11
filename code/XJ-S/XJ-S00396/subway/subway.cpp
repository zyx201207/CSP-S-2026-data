#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
	int x,y;
};
int w[510000],k[510],a[510][510],t[510][510],ans=0x3f3f3f,l,r;
bool vis[510000];
vector<node>v[51000000];
void dfs(int x,int sum){
	vis[x]=1;
	if(x==r){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i].x])continue;
		dfs(v[x][i].x,sum+v[x][i].y);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		v[i].push_back({i+m,w[i]});
		v[i+m].push_back({i,w[i]});
	}
	int cnt=2*m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt++;
			if(j>1){
				v[cnt-1].push_back({cnt,0});
				v[cnt].push_back({cnt-1,0});
			}
			v[a[i][j]+m].push_back({cnt,t[i][j]});
			v[cnt].push_back({a[i][j]+m,t[i][j]});
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		ans=0x3f3f3f;
		cin>>l>>r;
		dfs(l,0);
		cout<<ans<<'\n';
	}
	return 0;
}

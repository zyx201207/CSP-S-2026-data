#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1001];
struct node{
	int pos;
	int xian;
	int hao;
};
vector<node> v[1001];
int a[1001][1001];
int t[1001][1001];
int ans;
bool vis[1001];
void dfs(node x,int y,int ti){
	if(x.pos==y){
		ans=min(ans,ti)+w[y];
		return;
	}
	for(auto i:v[x.pos]){
		if(vis[i.pos])continue;
		vis[i.pos]=1;
		dfs(i,y,ti+t[i.xian][i.hao]+t[x.xian][x.hao]);
		vis[i.pos]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j];
			cin>>t[i][j];
			for(int k=1;k<=j;k++)v[a[i][j]].push_back({a[i][k],i,k});
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ans=0x3f3f3f3f;
		dfs({xr,0,0},yr,w[xr]);
		cout<<ans<<"\n";
	}
	return 0;
}
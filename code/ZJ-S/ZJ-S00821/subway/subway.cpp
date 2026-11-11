#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll ans=0x7f7f7f7f;
int w[500010];
vector<int>a[510];
int t[510][510];
void dfs(int u,int v,ll sum){
	if(sum>ans&&ans!=0x7f7f7f7f)return;
	if(u==v){
		ans=min(ans,sum);
		return;
	}
	for(auto it:a[u]){
		dfs(it,v,sum+t[u][it]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i][x]=y;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0x7f7f7f7f;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}
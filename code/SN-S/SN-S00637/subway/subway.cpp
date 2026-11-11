#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,w[500010],ans;
vector<pair<int,int> >ve[500010];
vector<int>tr[510];
void dfs(int st,int en,int sum){
	if(st==en){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)return;
	for(int i=0;i<tr[st].size();i++){
		int u=tr[st][i];
		int v;
		for(int j=0;j<ve[u].size();j++){
			if(ve[u][j].first==st){
				v=j;
				break;
			}
		}
		for(int j=0;j<ve[u].size();j++){
			if(ve[u][j].first==st)continue;
			dfs(ve[u][j].first,en,sum+ve[u][j].second+ve[u][v].second);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ve[a].push_back({i,t});
			tr[i].push_back(a);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<ve[x].size();i++){
			for(int j=0;j<ve[y].size();j++){
				dfs(ve[x][i].first,ve[y][j].first,sum+ve[x][i].second+ve[y][j].second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

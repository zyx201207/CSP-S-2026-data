#include <bits/stdc++.h>
#include <vector>>
using namespace std;
int c,n,m,d,q,w[500005],k,l,r,ans,a,t;
vector<vector<pair<int,int> > >p;
void dfs(int x,int e,int s){
	if(x==e){
		ans=min(ans,s);
		return ;
	}
	if(s>ans)return ;
	for(int i=0;i<p[x].size();i++)dfs(p[x][i].first,e,s+p[x][i].second);
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			//p[a].push_back({i+1e9,t});
			//p[i+1e9].push_back({a,t});
		}
	}
	while(q--){
		ans=t;
		cin>>l>>r;
		//dfs(l,r,0);
		cout<<ans+w[l]+w[r]<<endl;
	}
	return 0;
 }

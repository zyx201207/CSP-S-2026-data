#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],ans,vis[500005];
vector<pair<int,int> > v[500005];
void  dfs(int x,int y,int sum){
	vis[x]=1;
	if(x==y){
		ans=min(ans,sum);
	}
	for(int i=0;i<v[x].size();i++){
		int yy=v[x][i].first;
		if(vis[yy]==1) continue;
		dfs(yy,y,sum+v[x][i].second);
		vis[yy]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a[500005],t[500005];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for(int l=1;l<=k[i];l++){
			for(int r=1;r<=k[i];r++){
				if(l==r) continue;
				v[a[l]].push_back({a[r],t[l]+t[r]});
				v[a[r]].push_back({a[l],t[l]+t[r]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		ans=1e9;
		cin>>s>>e;
		dfs(s,e,0);
		vis[s]=0;
		ans+=w[s]+w[e];
		cout<<ans<<'\n';
	}
	return 0;
}

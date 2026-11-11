#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,n,m,d,q;
int w[500005],k[505],dis[505][505];
vector<pair<int,int> > s[500005];
int s2[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s2[i][j]=0x3f3f3f3f3f3f3f3f;
			if(i==j)s2[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(s[i].size()==1)continue;
		for(int j=0;j<s[i].size();j++){
			for(int k=j+1;k<s[i].size();k++){
				int u=s[i][j].first,v=s[i][k].first;
				s2[u][v]=s[i][j].second+s[i][k].second;
				s2[v][u]=s[i][j].second+s[i][k].second;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s2[i][j]=min(s2[i][j],s2[i][k]+s2[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<s[u].size();j++){
			for(int k=0;k<s[v].size();k++){
				int q=s[u][j].first,e=s[v][k].first;
				ans=min(ans,s2[q][e]+s[u][j].second+s[v][k].second+w[u]+w[v]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
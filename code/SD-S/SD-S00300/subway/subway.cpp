// didn't understand the true meaning .i'm angry

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int n,m;
int c,d,q;
int W[500005];
int T[500005];

vector< pair<int,int> >hav[500005];

int g[505][505];



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>W[i];
	}	
	
	for (int i=1;i<=n;i++){
		int len;
		cin>>len;
		for (int j=1;j<=len;j++){
			int v,t;
			cin>>v>>t;
			hav[v].push_back(make_pair(i,t));
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<hav[i].size();j++){
			for (int k=j+1;k<hav[i].size();k++){
				int s=hav[i][j].first;
				int t=hav[i][k].first;
				int ws=hav[i][j].second;
				int wt=hav[i][k].second;
				
				g[s][t]=min(g[s][t],ws+wt);
				g[t][s]=g[s][t];
			}
		}
	}
	for (int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for (int i=0;i<hav[x].size();i++){
			for (int j=0;j<hav[y].size();j++){
				ans=min(ans,W[x]+W[y]+g[hav[x][i].first][hav[y][j].first]+hav[x][i].second+hav[y][j].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

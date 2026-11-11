#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
#define int long long
const int inf=1e18;
int cid,n,m,d,Q,w[500005],f[505][505];
vector<pair<int,int> > q[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>cid>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			q[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)q[i].size();j++){
			for(int k=j+1;k<(int)q[i].size();k++){
				int x=q[i][j].first,y=q[i][k].first,w=q[i][j].second+q[i][k].second;
				f[x][y]=f[y][x]=min(f[x][y],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int tt=1,s,t,ans;tt<=Q;tt++){
		cin>>s>>t;ans=inf;
		for(int i=0;i<(int)q[s].size();i++){
			for(int j=0;j<(int)q[t].size();j++){
				int x=q[s][i].first,y=q[t][j].first,w=q[s][i].second+q[t][j].second;
				ans=min(ans,f[x][y]+w);
			}
		}
		ans+=w[s]+w[t];
		cout<<ans<<endl;
	}
	return 0;
}

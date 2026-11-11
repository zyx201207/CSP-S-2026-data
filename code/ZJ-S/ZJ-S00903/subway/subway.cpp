#include<bits/stdc++.h>
using namespace std;
long long w[514114];
vector<pair<long long,long long>> sta[514114];
long long g[514][514];
const long long inf=0x3f3f3f3f3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k,a,t,x,y,ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=inf;
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			for(auto p:sta[a]){
				g[p.first][i]=min(g[p.first][i],p.second+t);
				g[i][p.first]=min(g[i][p.first],p.second+t);
			}
			sta[a].push_back({i,t});
		}
	}
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(g[i][j]+g[i][k]<g[j][k]){
						flag=true;
						g[j][k]=g[i][j]+g[i][k];
						g[k][j]=g[i][j]+g[i][k];
					}
				}
			}
		}
	}
	for(int r=1;r<=q;r++){
		ans=inf;
		cin>>x>>y;
		for(auto pt1:sta[x]){
			for(auto pt2:sta[y]){
				ans=min(ans,g[pt1.first][pt2.first]+w[x]+w[y]+pt1.second+pt2.second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=5e5+15,maxm=505;
int _,n,m,d,q,w[maxn],dis[maxm][maxm],mx;
vector<array<int,2>> ve[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,x,t;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>x>>t;
			ve[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int sz=ve[i].size();
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++){
				if(j==k) continue;
				int x=ve[i][j][0],y=ve[i][k][0];
				dis[x][y]=min(dis[x][y],ve[i][j][1]+ve[i][k][1]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto v1:ve[x]){
			for(auto v2:ve[y]){
				int t1=v1[0],t2=v2[0];
				ans=min(ans,dis[t1][t2]+v1[1]+v2[1]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

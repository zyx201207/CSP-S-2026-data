#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
int k[510];
vector<int>e[500010];
vector<int>f[500010];
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			e[x].push_back(i);
			f[x].push_back(y);
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e17;
		}
	}
	int x,y,xx,yy,ans;
	bool flag;
	for(int i=1;i<=m;i++){
		int p=e[i].size();
		for(int j=0;j<p;j++){
			for(int k=j+1;k<p;k++){
				x=e[i][j],y=e[i][k];
				dis[x][y]=min(dis[x][y],f[i][j]+f[i][k]);
				dis[y][x]=dis[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i) continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
	while(q--){
		ans=1e18;
		cin>>x>>y;	
		xx=e[x].size();
		yy=e[y].size();
		flag=0;
		for(int i=0;i<xx;i++){
			for(int j=0;j<yy;j++){
				if(e[x][i]==e[y][j]){
					ans=min(ans,f[x][i]+f[y][j]);
					flag=1;
				}
			}
		}
		if(flag){
			cout<<ans+w[x]+w[y]<<endl;
			continue;
		}
		for(int i=0;i<xx;i++){
			for(int j=0;j<yy;j++){
				ans=min(ans,f[x][i]+f[y][j]+dis[e[x][i]][e[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long inf=1e18;
int c,n,m,d,q;
long long w[500010];
long long dis[501][501];
vector<int> s[500010],a[510];
long long t[500010][21];
void slve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			s[aa].push_back(i);
			t[aa][s[aa].size()-1]=tt;
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			dis[j][k]=inf;
			dis[k][j]=inf;
		}
		dis[j][j]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			for(int k=0;k<s[i].size();k++){
				int u=s[i][j],v=s[i][k];
				dis[u][v]=min(dis[u][v],t[i][j]+t[i][k]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	
	slve();
	for(int o=1;o<=q;o++){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+dis[s[x][i]][s[y][j]]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

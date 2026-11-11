#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010],dis[510][510];
struct node{
	int ln;
	long long t;
};
vector <node> sub[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;cin>>aa>>tt;
			sub[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sub[i].size();j++){
			for(int k=j+1;k<sub[i].size();k++){
				if(j==k)continue;
				dis[sub[i][j].ln][sub[i][k].ln]=dis[sub[i][k].ln][sub[i][j].ln]=min(dis[sub[i][j].ln][sub[i][k].ln],sub[i][j].t+sub[i][k].t);
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==mid||mid==i)continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<sub[x].size();i++){
			for(int j=0;j<sub[y].size();j++){
				ans=min(ans,w[x]+w[y]+dis[sub[x][i].ln][sub[y][j].ln]+sub[x][i].t+sub[y][j].t);
			}
		}
		cout<<ans<<"\n";
	}
}
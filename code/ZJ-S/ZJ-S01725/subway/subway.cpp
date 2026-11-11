#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=5e2+10,inf=1e18;
int c,n,m,d,q,w[N],k[M],x,y,dis[M][M];
vector<pair<int,int>>edg[N];
vector<int>a[M],t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			edg[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(pair<int,int>k:edg[a[i][j]]){
				dis[i][k.first]=min(dis[i][k.first],t[i][j]+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int mn=inf;
		for(pair<int,int>i:edg[x]){
			for(pair<int,int>j:edg[y]){
				mn=min(mn,i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<mn+w[x]+w[y]<<endl;
	}
	return 0;
}

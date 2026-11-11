#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,w[N],dis[505][505];
struct node{
	int id,tim;
};
vector<node> vec[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=1e15;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				node x=vec[i][j],y=vec[i][k];
				dis[x.id][y.id]=dis[y.id][x.id]=min(dis[x.id][y.id],x.tim+y.tim);
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
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(node u:vec[x]){
			for(node v:vec[y]){
				ans=min(ans,dis[u.id][v.id]+u.tim+v.tim);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}

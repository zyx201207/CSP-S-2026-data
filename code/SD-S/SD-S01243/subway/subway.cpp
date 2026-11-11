#include<bits/stdc++.h>
#define ll long long
#define N 505
#define M 500005
#define pil pair<int,ll>
#define id first
#define dis second
using namespace std;
int c,n,m,b,q;
ll a[M],d[N][N]/*第i,j条线之间的距离*/,ans;
vector<pil> v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>b>>q;
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,k;i<=n;i++){
		d[i][i]=0;
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++) d[v[i][j].id][v[i][k].id]=d[v[i][k].id][v[i][j].id]=min(d[v[i][j].id][v[i][k].id],v[i][j].dis+v[i][k].dis);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,d[v[x][i].id][v[y][j].id]+v[x][i].dis+v[y][j].dis);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}//15:35

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll w[500010];

struct node{
	ll l,t;
};
vector<node>e[500010];
ll l[510][510];
ll dis[2][510][510];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(l,0x3f,sizeof(l));
	ll c,n,m,d,q,k,a,t,len,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		l[i][i]=0;
		cin>>k;
		for(int o=1;o<=k;o++){
			cin>>a>>t;
			len=e[a].size();
			for(int j=0;j<len;j++){
				l[i][e[a][j].l]=min(l[i][e[a][j].l],t+e[a][j].t);
				l[e[a][j].l][i]=min(l[e[a][j].l][i],t+e[a][j].t);
			}
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[0][i][j]=dis[1][i][j]=l[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=n;i>=1;i--){
			for(int j=n;j>=1;j--){
				dis[k&1][i][j]=min(dis[!(k&1)][i][j],dis[!(k&1)][i][k]+dis[!(k&1)][k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int lx=e[x].size(),ly=e[y].size();
		ll mn=LLONG_MAX;
		for(int i=0;i<lx;i++){
			for(int j=0;j<ly;j++){
				mn=min(mn,w[x]+e[x][i].t+dis[n&1][e[x][i].l][e[y][j].l]+e[y][j].t+w[y]);
			}
		}
		cout<<mn<<'\n';
	}
	cout<<endl;
	return 0;
}

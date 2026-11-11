#include<iostream>
#include<vector>

using namespace std;
const int M=500005;
struct Sta{
	long long l,t;
};
long long g[505][505];
int c,n,m,d,q;
long long w[M];
vector <Sta> s[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<505;i++){
		for(int j=0;j<505;j++){
			g[i][j]=1e18;
			if(i==j)g[i][j]=0;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			s[a].push_back({i,t});
		}
	}
	for(int x=1;x<=m;x++){
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[x].size();j++){
				if(i==j)continue;
				g[s[x][i].l][s[x][j].l]=min(g[s[x][i].l][s[x][j].l],s[x][i].t+s[x][j].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][k]+g[k][j]<g[i][j])g[i][j]=g[i][k]+g[k][j];
			}
		}
	}
	while(q--){
		long long x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				long long val=s[x][i].t+s[y][j].t+g[s[x][i].l][s[y][j].l];
				if(ans>val){
					ans=val;
				}
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}


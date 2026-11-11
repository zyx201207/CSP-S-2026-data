#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;

const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
ll a[M],f[N][N];
struct node{
	int p;
	ll t;
};
vector<node> w[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			w[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<w[i].size();j++){
			for(int k=j+1;k<w[i].size();k++){
				f[w[i][j].p][w[i][k].p]=f[w[i][k].p][w[i][j].p]=min(f[w[i][j].p][w[i][k].p],w[i][j].t+w[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0ll;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto i:w[x]){
			for(auto j:w[y]){
				int p1=i.p,p2=j.p;
				ll t1=i.t,t2=j.t;
				ans=min(ans,f[p1][p2]+t1+t2);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
constexpr long long inf=LLONG_MAX>>1;
int n,m,c,d,q,x,y,a[500010];
long long ans,f[510][510];
struct node{int x,y;};
vector<node> g[500010];
bool p[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j) f[i][j]=inf;
	for (int i=1,u;i<=n;i++){
		cin>>u;
		for (int j=1;j<=u;j++){
			cin>>x>>y;
			for (node l:g[x]){
				f[i][l.x]=f[l.x][i]=min(f[i][l.x],(long long)y+l.y);
				p[i][l.x]=p[l.x][i]=true;
			}
			g[x].push_back({i,y});
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while (q--){
		cin>>x>>y;ans=inf;
		for (node i:g[x]) for (node j:g[y])
			ans=min(ans,f[i.x][j.x]+i.y+j.y);
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}

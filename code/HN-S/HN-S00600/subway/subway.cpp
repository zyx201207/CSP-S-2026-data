#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=505;
int c,n,m,d,q;
int w[N];
struct S{
	int l,t;
};
vector<S> e[N];
ll f[M][M];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	fill(f[0],f[0]+M*M,1e18);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			int lin1=e[i][j].l,tim1=e[i][j].t;
			for(int k=j+1;k<e[i].size();k++){
				int lin2=e[i][k].l,tim2=e[i][k].t;
				f[lin1][lin2]=f[lin2][lin1]=min(f[lin1][lin2],(ll)tim1+tim2);
			}
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		ll cnt=w[x]+w[y];
		for(int i=0;i<e[x].size();i++){
			int lin1=e[x][i].l,tim1=e[x][i].t;
			for(int j=0;j<e[y].size();j++){
				int lin2=e[y][j].l,tim2=e[y][j].t;
				ans=min(ans,cnt+tim1+tim2+f[lin1][lin2]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


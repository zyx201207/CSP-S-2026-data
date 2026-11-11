#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
vector<int> a[N],t[N];
vector<int> top[M],id[M];
ll g[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
				if(i!=j)	g[i][j]=1e18;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0,rx,rw;j<k[i];j++){
			cin>>rx>>rw;
			a[i].push_back(rx);
			t[i].push_back(rw);
			top[rx].push_back(i);
			id[rx].push_back(j);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j_1=0;j_1<top[i].size();j_1++){
			for(int j_2=0;j_2<top[i].size();j_2++){
				if(j_1==j_2)	continue;
				int x=top[i][j_1],y=top[i][j_2],xi=id[i][j_1],yi=id[i][j_2];
				g[y][x]=g[x][y]=min(g[x][y],0ll+t[x][xi]+t[y][yi]);
			}
		}
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
	while(q--){
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(int j_1=0;j_1<top[x].size();j_1++){
			for(int j_2=0;j_2<top[y].size();j_2++){
				int tx=top[x][j_1],ty=top[y][j_2],xi=id[x][j_1],yi=id[y][j_2];
				ans=min(ans,g[tx][ty]+t[tx][xi]+t[ty][yi]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
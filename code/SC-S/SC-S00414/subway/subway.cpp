#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[(int)1e6+10];
struct node{
	int to,w;
};
vector<node>g[(int)1e6+10];
int f[1010][1010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("C:\\Users\\user\\Documents\\down\\subway\\subway4.in","r",stdin);
//	freopen("D:\\work\\out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int to1=g[i][j].to,to2=g[i][k].to,w1=g[i][j].w,w2=g[i][k].w;
				f[to1][to2]=f[to2][to1]=min(w1+w2,f[to1][to2]);
			}
		}
	}
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
		int ans=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int to1=g[x][i].to,to2=g[y][j].to;
				int w1=g[x][i].w,w2=g[y][j].w;
				ans=min(ans,f[to1][to2]+w[x]+w[y]+w1+w2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
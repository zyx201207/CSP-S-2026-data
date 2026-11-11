#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,x,y,ans;
int w[N],k[N],t[510][510];
struct node{
	int a,t;
};
vector<node>g[N],a[510];
void dfs(int x,int yx,int c){
	for(int i=0;i<a[x].size();i++){
		int ta=a[x][i].a,tt=a[x][i].t;
		for(int j=0;j<g[ta].size();j++){
			int y=g[ta][j].a,tk=g[ta][j].t;
			if(y==x){
				continue;
			}
			else{
				if(tt+tk+c<=t[yx][y]){
					t[yx][y]=min(t[yx][y],tk+tt+c);
					t[y][yx]=min(t[y][yx],tk+tt+c);
					dfs(y,yx,tt+tk+c);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			g[x].push_back({i,y});
			a[i].push_back({x,y});
		}
	}
	memset(t,0x3f,sizeof t);
	for(int i=1;i<=n;i++){
		t[i][i]=0;
		dfs(i,i,0);
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int kx=0;kx<g[x].size();kx++){
			for(int ky=0;ky<g[y].size();ky++){
				ans=min(ans,g[x][kx].t+t[g[x][kx].a][g[y][ky].a]+g[y][ky].t);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}


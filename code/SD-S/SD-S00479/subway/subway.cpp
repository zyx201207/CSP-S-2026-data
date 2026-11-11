#include<bits/stdc++.h>
#define ll long long
#define pr(x) pair<x,x>
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=5e2+10,M=5e5+10,D=2e1+10;
const ll INF=1e18;
int c,n,m,d,q;
int w[M];
struct edge{
	int v,w;
};
vector<edge> tlx[M];
ll cg[N][N];
ll ans;
void solve()
{
	cin>>c>>n>>m>>d>>q;
	up(i,1,m,1){
		cin>>w[i];
	}
	up(i,1,n,1){
		up(j,1,n,1){
			if(i!=j){
				cg[i][j]=INF;
			}
		}
	}
	int k,a,t,lst;
	up(i,1,n,1){
		cin>>k;
		lst=0;
		up(j,1,k,1){
			cin>>a>>t;
			tlx[a].push_back({i,t});
		}
	}
	up(i,1,m,1){
		up(j,0,(int)tlx[i].size()-1,1){
			up(k,j+1,(int)tlx[i].size()-1,1){
				cg[tlx[i][j].v][tlx[i][k].v]=cg[tlx[i][k].v][tlx[i][j].v]=tlx[i][j].w+tlx[i][k].w;
			}
		}
	}
	up(k,1,n,1){
		up(i,1,n,1){
			up(j,1,n,1){
				cg[i][j]=min(cg[i][j],cg[i][k]+cg[k][j]);
			}
		}
	}
	int x,y;
	up(xw,1,q,1){
		cin>>x>>y;
		ans=INF;
		up(i,0,(int)tlx[x].size()-1,1){
			up(j,0,(int)tlx[y].size()-1,1){
				ans=min(ans,tlx[x][i].w+cg[tlx[x][i].v][tlx[y][j].v]+tlx[y][j].w);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
	//cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
}


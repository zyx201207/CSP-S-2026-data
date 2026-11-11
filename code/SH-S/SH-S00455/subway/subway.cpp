#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=510;
const int M=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,d,q;
int a[M];
vector<array<int,2>> vec[M];
ll dst[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1,k,x,w;i<=n;i++){
		cin>>k;
		while(k--)
			cin>>x>>w,vec[x].push_back({i,w});
	}
	memset(dst,0x3f,sizeof(dst));
	for(int i=1;i<=m;i++)
		for(int j=0;j<vec[i].size();j++){
			int u=vec[i][j][0],w1=vec[i][j][1];
			for(int k=j+1;k<vec[i].size();k++){
				int v=vec[i][k][0],w2=vec[i][k][1];
				dst[u][v]=min<ll>(dst[u][v],w1+w2),dst[v][u]=min<ll>(dst[v][u],w1+w2);
			}
		}
	for(int i=1;i<=n;i++)
		dst[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=inf;
		for(int j=0;j<vec[x].size();j++){
			int u=vec[x][j][0],w1=vec[x][j][1];
			for(int k=0;k<vec[y].size();k++){
				int v=vec[y][k][0],w2=vec[y][k][1];
				ans=min(ans,a[x]+a[y]+dst[u][v]+w1+w2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

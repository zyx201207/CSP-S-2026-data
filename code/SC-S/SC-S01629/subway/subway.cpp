#include<bits/stdc++.h>
#define M 500002
#define N 502
#define ll long long
using namespace std;
const ll inf=1e18;
int c,n,m,d,q,num,A,B,F,T;
int w[M];
ll g[N][N],ans;
vector<int> vec[M]; // 每个地铁站连接的地铁 
vector<int> to[M];
inline void addE(int x,int y,ll z){
	g[x][y]=min(g[x][y],z);
	g[y][x]=min(g[y][x],z);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i]; 
	for(int i=1; i<=n; i++){
		cin>>num;
		while(num--){
			cin>>A>>B;
			vec[A].push_back(i);
			to[A].push_back(B);
		}
		for(int j=1; j<=n; j++) g[i][j]=inf;
		g[i][i]=0;
	}
	for(int i=1; i<=m; i++)
		for(int j=0; j<(int)vec[i].size(); j++)
			for(int k=j+1; k<(int)vec[i].size(); k++)
				addE(vec[i][j],vec[i][k],to[i][j]+to[i][k]);
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		cin>>F>>T;
		ans=inf;
		for(int j=0; j<(int)vec[F].size(); j++)
			for(int k=0; k<(int)vec[T].size(); k++)
				ans=min(ans,g[vec[F][j]][vec[T][k]]+to[F][j]+to[T][k]);
		cout<<ans+w[F]+w[T]<<"\n";
	}
	return 0;
} 
#include<bits/stdc++.h>
#define M 500005
#define N 505
using namespace std;
int c,n,m,d,q,w[M];
struct Node{
	int pos,t;
};
vector<Node>can[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int c,p,t;cin>>c;
		while(c--)cin>>p>>t,
			can[p].push_back({i,t});
	}for(int i=1;i<=m;i++){
		for(Node j:can[i])for(Node k:can[i])if(j.pos!=k.pos){
			long long D=dis[j.pos][k.pos],now=j.t+k.t;
			if(D>now)dis[j.pos][k.pos]=dis[k.pos][j.pos]=now;
		}
	}for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=1e18;
		for(Node i:can[x])for(Node j:can[y])
		ans=min(ans,dis[i.pos][j.pos]+i.t+j.t);cout<<ans+w[x]+w[y]<<"\n";
	}return 0;
}
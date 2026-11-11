#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=500,M=5e+5;
int w[M+10];
int x,y;
struct p{
	int a,t;
};
vector <p > g[M+N+10];

int vis[500*M+10];
ll ans=1e+9;
void bfs(int l,int r,ll sum){	
	if(sum>ans)	return ;
	if(l==r){
		ans=sum;
		return ;
	} 
	for(int i=0;i<g[l].size();i++){
		p v=g[l][i];
		if(vis[v.a])	continue;
		vis[v.a]=1;
		bfs(v.a,r,sum+v.t);
		vis[v.a]=0;
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;	cin>>k;
		for(int j=1;j<=k;j++){
			p q;	cin>>q.a>>q.t;
			g[i+m].push_back(q);
			p r;	r.t=q.t;	r.a=i+m;
			g[q.a].push_back(r);
		}
	}
	while(q--){
		ans=1e+9;
		cin>>x>>y;
		bfs(x,y,0);
		cout<<ans+w[x]+w[y]<<"\n";	
	}
	
	return 0;
}
